cmake_minimum_required(VERSION 3.2)

add_executable(run-test
  test_runner.cpp
  test_basic.cpp
)

add_test(NAME run-test COMMAND run-test)
