cmake_minimum_required(VERSION 3.2)

project(template)

add_executable(app
  src/main.cpp
)

# Testing
enable_testing()

add_subdirectory(tests)
