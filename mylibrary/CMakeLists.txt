cmake_minimum_required(VERSION 3.2)

# static library
add_library(mylibrary STATIC
  src/mylibrary.cpp
)

target_include_directories(mylibrary PRIVATE include)

# dynamic library
add_library(mylibrary-dynamic SHARED
  src/mylibrary.cpp
)

set_target_properties(mylibrary-dynamic PROPERTIES
  C_VISIBILITY_PRESET hidden
  CXX_VISIBILITY_PRESET hidden
  VISIBILITY_INLINES_HIDDEN YES
)

target_compile_definitions(mylibrary-dynamic PRIVATE DLL_EXPORTS)
target_include_directories(mylibrary-dynamic PRIVATE include)
