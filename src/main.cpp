#include "mylibrary.hpp"
#include <iostream>

int main()
{
    std::cout << "Call function: " << mylibrary::sum(1, 2) << '\n';
    mylibrary::examples::std_vector_custom_allocator();
    return 0;
}
