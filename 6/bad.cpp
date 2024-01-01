#include <iostream>

int getNumber()
{
    int num {};
    std::cin >> num;

    return num;
}

int main()
{
    // this is better
    // int num { getNumber() };

    // you don't know which getNumber() is evaluated first
    std::cout << getNumber() + (getNumber() * getNumber()) << '\n';

    return 0;
}
