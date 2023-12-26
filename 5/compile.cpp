#include <iostream>

int five()
{
    return 5;
}

int main()
{
    int age {};

    std::cin >> age;

    constexpr int error { five() };

    return 0;
}
