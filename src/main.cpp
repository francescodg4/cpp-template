#include "mylibrary.hpp"
#include <iostream>
#include <spdlog/spdlog.h>

int main()
{
    std::cout << "Call function: " << mylibrary::sum(1, 2) << '\n';
    mylibrary::examples::std_vector_custom_allocator();

#ifndef NDEBUG
    spdlog::set_level(spdlog::level::debug);
#endif

    spdlog::debug("Debug - Hello, world!");
    spdlog::info("Hello, world!");

    return 0;
}
