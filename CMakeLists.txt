cmake_minimum_required(VERSION 3.15)
project(jsonparser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_BUILD_TYPE Release)

# Add profiling flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")

include_directories(
  include/JSONParser
  lib/valijson/include
  lib/rapidjson/include
)

add_executable(demo
  demo/demo.cpp  
  src/jsonparser.cpp
)
add_dependencies(demo copy-files)

# Copy demo files.
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/bin/demofiles/)
add_custom_target(copy-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ../demo/demofiles
    ${CMAKE_BINARY_DIR}/bin/demofiles
)
