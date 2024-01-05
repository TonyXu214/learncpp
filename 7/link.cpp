#include <iostream>

[[maybe_unused]] static int g_x {}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword
// int g_x {}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

const int g_y { 1 }; // const globals have internal linkage by default
constexpr int g_z { 2 }; // constexpr globals have internal linkage by default

int main()
{
    std::cout << g_x << '\n';
    std::cout << g_y << '\n';
    std::cout << g_z << '\n';

    return 0;
}
