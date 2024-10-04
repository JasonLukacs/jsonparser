cmake_minimum_required(VERSION 3.15)
project(jsonparser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_BUILD_TYPE Release)

include_directories(
  include/JSONParser
  lib/valijson/include
  lib/rapidjson/include
)

add_executable(demo
  demo/demo.cpp  
  src/jsonparser.cpp
)

# Copy demo files.
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/demofiles/)

add_custom_command(
    TARGET demo
    PRE_BUILD
    COMMAND cp ../demo/demofiles/schema_correct.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    COMMAND cp ../demo/demofiles/json_correct.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    COMMAND cp ../demo/demofiles/schema_corrupt.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    COMMAND cp ../demo/demofiles/json_corrupt.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    
    DEPENDS ../demo/demofiles/schema_correct.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    DEPENDS ../demo/demofiles/json_correct.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    DEPENDS ../demo/demofiles/schema_corrupt.json ${CMAKE_BINARY_DIR}/bin/demofiles/
    DEPENDS ../demo/demofiles/json_corrupt.json ${CMAKE_BINARY_DIR}/bin/demofiles/
)