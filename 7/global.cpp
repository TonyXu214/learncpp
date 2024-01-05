#include <iostream>

// const int g; // error: constant variables must be initialized
// constexpr int g_y; // error: constexpr variables must be initialized

const int g_one { 1 };
constexpr int g_two { 2 };

namespace tony
{
    int g_x {};
}

void dos()
{
    tony::g_x = 5;
    std::cout << tony::g_x << '\n';
    std::cout << g_one << '\n';
    std::cout << g_two << '\n';
}

int main()
{
    dos();

    tony::g_x = 4;
    std::cout << tony::g_x << '\n';

    return 0;
}
