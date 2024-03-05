#include <array>
#include <iostream>

int main()
{
    constexpr std::array arr { 1, 2, 3, 4, 5 };
    std::cout << std::get<0>(arr) << '\n'; // compile time bounds checking
    // std::cout << std::get<6>(arr) << '\n'; // compile time bounds checking

    return 0;
}
