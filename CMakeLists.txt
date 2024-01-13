cmake_minimum_required(VERSION 3.2)

project(CppTemplateProject VERSION 0.0.0)

add_executable(application
  src/main.cpp
)

# Statically linked library
add_subdirectory(mylibrary)

target_link_libraries(application PRIVATE mylibrary)
target_include_directories(application PRIVATE mylibrary/include)

# Testing
add_subdirectory(tests)
