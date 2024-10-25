#include <iostream>

#include "mylibrary.hpp"

int main()
{
    foo();
    std::cout << "Call function: " << mylibrary::sum(1, 2) << '\n';
    mylibrary::examples::std_vector_custom_allocator();
    return 0;
}
