cmake_minimum_required(VERSION 3.16)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(run-test
  test_basic.cpp
)

target_link_libraries(run-test PRIVATE Catch2::Catch2WithMain)

target_include_directories(run-test PRIVATE ../mylibrary/include)
target_link_libraries(run-test PRIVATE mylibrary)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)
catch_discover_tests(run-test)
