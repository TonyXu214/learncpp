#include <iostream>

int main()
{
    double x { 100.0 - 99.99 };
    double y { 10.0 - 9.99 };

    if (x == y)
        std::cout << "equal" << '\n';
    else if (x > y)
        std::cout << "greater" << '\n';
    else
        std::cout << "less" << '\n';

    return 0;
}
