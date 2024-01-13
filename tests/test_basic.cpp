#include "mylibrary.hpp"
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

static int Factorial(int number)
{
    return number <= 1 ? 1 : Factorial(number - 1) * number;
}

TEST_CASE("Factorial tests", "[factorial]")
{
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Factorial benchmark", "[benchmark]")
{
    BENCHMARK("Factorial 25")
    {
        return Factorial(25);
    };

    BENCHMARK("Factorial 50")
    {
        return Factorial(50);
    };
}

TEST_CASE("Check mylibrary::function", "[mylibrary]")
{
    REQUIRE(mylibrary::function(4, 5) == 9);
    REQUIRE(mylibrary::function(3, 4) == 7);
}
