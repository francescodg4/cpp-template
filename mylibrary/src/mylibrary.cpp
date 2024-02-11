#include "mylibrary.hpp"
#include <iostream>
#include <memory>
#include <vector>

void foo()
{
}

namespace mylibrary {

int sum(int a, int b)
{
    return a + b;
}

namespace examples {

    template <typename T>
    class CustomAllocator {
    public:
        using value_type = T;

        T* allocate(std::size_t n_elements)
        {
            std::cout << "CustomAllocator::allocate("
                      << std::dec
                      << n_elements << ");"
                      << '\n';
            return static_cast<T*>(::operator new(n_elements * sizeof(T)));
        }

        void deallocate(T* ptr, std::size_t n_elements)
        {
            std::cout << "CustomAllocator::deallocate(0x"
                      << std::hex << (uintptr_t)(ptr) << ", "
                      << std::dec << n_elements << ");"
                      << '\n';
            ::operator delete(ptr);
        }
    };

    void std_vector_custom_allocator()
    {
        std::vector<int, CustomAllocator<int>> a_vector;

        a_vector.reserve(10); // memory is allocated here

        std::cout << "(1) a_vector.begin address: 0x" << std::hex << (uintptr_t)(&a_vector[0]) << '\n';

        std::fill_n(std::back_inserter(a_vector), 10, 42); // does not cause allocation as memory has been already reserved

        a_vector.push_back(42); // a reallocation is requested here

        std::cout << "(3) a_vector.begin address: 0x" << std::hex << (uintptr_t)(&a_vector[0]) << '\n';
    }
} // namespace examples

} // namespace mylibrary
