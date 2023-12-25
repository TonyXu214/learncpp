#include <iostream>

int abs(int x)
{
    if (x < 0)
        return -x;

    return x;
}

int main()
{
    int x{};

    std::cout << "Please enter a number: " << std::endl;

    std::cin >> x;

    if (x == 0)
        std::cout << "x is 0" << std::endl;

    std::cout << abs(-4) << std::endl;
    std::cout << abs(5) << std::endl;

    return 0;
}
