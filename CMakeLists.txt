cmake_minimum_required(VERSION 3.14)
project(json_parser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

include_directories(
  include
  lib/valijson/include
  lib/valijson/include/valijson
  lib/valijson/include/valijson/adapters
  lib/valijson/include/valijson/utils
  lib/rapidjson/include
)

add_executable(schemavalidator
  main.cpp  
  src/json.cpp
)

