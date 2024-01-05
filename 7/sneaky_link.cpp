#include <iostream>

[[maybe_unused]] static int g_x {}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword
// int g_x {}; // non-constant globals have external linkage by default, but can be given internal linkage via the static keyword

[[maybe_unused]] const int g_y { 1 }; // const globals have internal linkage by default
[[maybe_unused]] constexpr int g_z { 2 }; // constexpr globals have internal linkage by default
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}
// int main_s()
// {
//     // std::cout << g_x << '\n';
//     std::cout << g_y << '\n';
//     std::cout << g_z << '\n';
//
//     return 0;
// }
