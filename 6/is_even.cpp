#include <iostream>

int main()
{
    std::cout << "enter a number: " << '\n';

    int num {};

    std::cin >> num;

    std::cout << ((num % 2 == 0) ? "is Even" : "is Odd") << '\n';

    return 0;
}
