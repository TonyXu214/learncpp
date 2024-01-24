#include "default.hpp"

#include <iostream>

// does not work, everything else after needs to be defaulted
// void badPrint(int x=10, y)
// {
//     std::cout << x << " " << y << '\n';
// }

void test_default(int x, int y)
{
    std::cout << x << " " << y << '\n';
}

void print(int x, int y=10)
{
    std::cout << x << " " << y << '\n';
}

int main()
{
    print(5);
    print(1, 2);

    test_default(1);

    return 0;
}
