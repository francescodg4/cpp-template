cmake_minimum_required(VERSION 3.16)

project(CppTemplateProject VERSION 0.0.0)

Include(FetchContent)

# ---- spdlog ----
FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.15.3
)
FetchContent_MakeAvailable(spdlog)

# ---- argparse ----
FetchContent_Declare(
  argparse
  GIT_REPOSITORY https://github.com/p-ranav/argparse.git
  GIT_TAG v3.2
)
FetchContent_MakeAvailable(argparse)


add_executable(application
  src/main.cpp
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
configure_file(src/version.h.in version.h)

# Statically linked library
add_subdirectory(mylibrary)

target_link_libraries(application PRIVATE mylibrary)
target_include_directories(application PRIVATE mylibrary/include)

target_link_libraries(application PRIVATE spdlog argparse)

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
