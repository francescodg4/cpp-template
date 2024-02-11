#ifndef MY_LIBRARY_HPP
#define MY_LIBRARY_HPP

extern "C" void foo();

namespace mylibrary {

/**
 * @brief Returns the sum of two numbers
 */
int sum(int a, int b);

} // namespace mylibrary

#endif /* MY_LIBRARY_HPP */
