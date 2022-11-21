cmake_minimum_required(VERSION 3.17)
project(hao)

set(CMAKE_CXX_STANDARD 20)

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
                    headers/engine.hpp 
                    headers/protobuf_wrapper.hpp 
                    src/protobuf_wrapper.cpp
                    game_states/state.hpp
                    game_states/state.cpp
                    game_states/game_state.hpp
                    game_states/game_state.cpp)

include_directories(${CMAKE_SOURCE_DIR}/libs/)
include_directories(${CMAKE_SOURCE_DIR}/game_states/)
include_directories(headers /usr/include c:/SFML/include)

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
