#include <iostream>
#include <spdlog/spdlog.h>
#include <argparse/argparse.hpp>

#include "mylibrary.hpp"

int main(int argc, char* argv[])
{
    argparse::ArgumentParser program("Application");

    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        return EXIT_FAILURE;
    }

    spdlog::info("Hello, world");
    spdlog::error("This is an error message with arg: {}", 1);

    foo();

    std::cout << "Call function: " << mylibrary::sum(1, 2) << '\n';
    mylibrary::examples::std_vector_custom_allocator();

    return EXIT_SUCCESS;
}
