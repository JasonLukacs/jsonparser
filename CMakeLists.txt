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
