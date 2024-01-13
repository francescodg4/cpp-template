cmake_minimum_required(VERSION 3.2)

add_library(mylibrary STATIC
  src/mylibrary.cpp
)

target_include_directories(mylibrary PRIVATE include)
