#include <iostream>

int main()
{
    constexpr double grav { 9.8 };

    if constexpr (grav == 9.8)
    {
        std::cout << "is 9.8" << '\n';
    } else
    {
        std::cout << "not" << '\n';
    }

    return 0;
}
