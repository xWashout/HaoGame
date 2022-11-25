cmake_minimum_required(VERSION 3.17)
project(hao)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 0)
# GOOGLE PROTOCOL BUFFERS
file(GLOB PROTOBUF_DEFINITION_FILES "${PROJECT_SOURCE_DIR}/proto_files/*.proto")
set(PROTOBUF_INPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/proto_files")
set(PROTOBUF_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/proto_files")
set (proto_command "protoc")

foreach(file ${PROTOBUF_DEFINITION_FILES})
    message(STATUS "Compiling proto file=${file}")
    set (proto_args --proto_path=${PROTOBUF_INPUT_DIRECTORY} --cpp_out=${PROTOBUF_OUTPUT_DIRECTORY} ${file})
    execute_process(COMMAND ${proto_command} ${proto_args}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    RESULT_VARIABLE proto_result)
    message(STATUS "Proto compilation exit code=${proto_result}")
endforeach()
file(GLOB PROTOBUF_MODELS_INCLUDES "proto_files/*.pb.cc" "proto_files/*.hpp")
# END GOOGLE PROTOCOL BUFFERS

add_executable(hao  src/main.cpp 
                    src/engine.cpp 
                    src/keybinds_config.cpp
                    game_states/state.cpp
                    game_states/game_state.cpp
                    entities/entity.cpp
                    proto_files/keybinds_config.pb.cc)

include_directories(${CMAKE_SOURCE_DIR}/libs/)
include_directories(${CMAKE_SOURCE_DIR}/game_states/)
include_directories(${CMAKE_SOURCE_DIR}/entities/)
include_directories(${CMAKE_SOURCE_DIR}/common/)
include_directories(${CMAKE_SOURCE_DIR}/proto_files/)
include_directories(headers /usr/include c:/SFML/include)
include_directories(C:/protobuf/protobuf-3.21.9/src/)

set(SFML_ROOT c:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(hao ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
