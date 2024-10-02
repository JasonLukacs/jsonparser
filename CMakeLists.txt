cmake_minimum_required(VERSION 3.15)
project(json_parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_BUILD_TYPE Release)

include_directories(
  include/JSONParser
  lib/valijson/include
  lib/rapidjson/include
)

add_executable(schemavalidator
  main.cpp  
  src/jsonparser.cpp
)

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/.git/modules")
    # If the .git/modules directory doesn't exist, the submodules are not initialized
    message(WARNING "Submodules are not initialized. Running 'git submodule init' and 'git submodule update'.")
    add_custom_command(
        TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND git submodule init
        COMMAND git submodule update --recursive
        COMMENT "Initializing and updating submodules"
    )
endif()