#ifndef MY_LIBRARY_HPP
#define MY_LIBRARY_HPP

#if defined _WIN32 || defined __CYGWIN__
#define SYMBOL_EXPORT __declspec(dllexport)
#define SYMBOL_IMPORT __declspec(dllimport)
#else
#define SYMBOL_EXPORT __attribute__((visibility("default")))
#define SYMBOL_IMPORT
#endif

#ifdef DLL_EXPORTS
#define MY_LIBRARY_API SYMBOL_EXPORT
#else
#define MY_LIBRARY_API SYMBOL_IMPORT
#endif

extern "C" MY_LIBRARY_API void foo();

namespace mylibrary {

/**
 * @brief Returns the sum of two numbers
 */
MY_LIBRARY_API int sum(int a, int b);

namespace examples {
    MY_LIBRARY_API void std_vector_custom_allocator();
}

} // namespace mylibrary

#endif /* MY_LIBRARY_HPP */
