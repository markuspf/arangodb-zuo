cmake_minimum_required(VERSION 3.22)
project(arangodb-zuo)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(fmt)

add_executable(arangodb-zuo
  main.cpp)

target_link_libraries(arangodb-zuo
  fmt
  zuo)

add_subdirectory(zuo)
