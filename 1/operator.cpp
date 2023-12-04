#include <iostream>

int main()
{
    int x { 5 };

    std::cout << (x = 10) << std::endl; // x is returned

    return 0;
}
