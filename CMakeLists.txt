cmake_minimum_required(VERSION 3.24)
project(arangodb-zuo)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 9.1.0)
FetchContent_MakeAvailable(fmt)

add_executable(arangodb-zuo
  main.cpp)

target_link_libraries(arangodb-zuo
  fmt
  zuo)

add_subdirectory(zuo)
