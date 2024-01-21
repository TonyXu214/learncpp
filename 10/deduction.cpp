#include <iostream>

auto subtract(int x, int y) -> int // trailing return type
{
    return x - y;
}

auto add(int x, int y)
{
    return x + y;
}

auto foo(); // forward declarations do not work

int main()
{
    using namespace std::string_view_literals;

    constexpr int test { 7 };
    auto y { x }; // type will be of int, not contexpr int
    constexpr auto z { x }; // type will be of constexpr int

    auto s { "Hello world" }; // will be of type const char *, not std::string
    auto t { "Hello world"sv }; // will be of type std::string_view

    std::cout << x << " " << y << '\n';

    return 0;
}
