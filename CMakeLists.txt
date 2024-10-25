cmake_minimum_required(VERSION 3.16)

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

# Install
install(TARGETS application RUNTIME DESTINATION bin)
install(
  DIRECTORY mylibrary/include/
  DESTINATION include
  FILES_MATCHING PATTERN "*.h*")

# Packaging
set(CPACK_PACKAGE_NAME "CppApplication")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "maintainer")
set(CPACK_PACKAGE_CONTACT "maintainer@email.com")

include(CPack)
