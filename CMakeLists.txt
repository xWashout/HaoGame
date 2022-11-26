cmake_minimum_required(VERSION 3.16)
project(hao)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(Protobuf REQUIRED)
find_package(SFML REQUIRED system window graphics)
find_package(spdlog REQUIRED)

# GOOGLE PROTOCOL BUFFERS - PROTO FILES COMPILATION
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
# END OF GOOGLE PROTOCOL FILES COMPILATION

include_directories(${CMAKE_SOURCE_DIR}/game_states/)
include_directories(${CMAKE_SOURCE_DIR}/entities/)
include_directories(${CMAKE_SOURCE_DIR}/common/)
include_directories(${CMAKE_SOURCE_DIR}/proto_files/)
include_directories(headers /usr/include)

add_executable(hao  src/main.cpp 
                    src/engine.cpp 
                    src/keybinds_config.cpp
                    game_states/state.cpp
                    game_states/game_state.cpp
                    entities/entity.cpp
                    proto_files/keybinds_config.pb.cc)

target_link_libraries(hao PUBLIC ${Protobuf_LIBRARIES})
target_link_libraries(hao PUBLIC spdlog::spdlog)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(hao PUBLIC ${SFML_LIBRARIES})
endif()


