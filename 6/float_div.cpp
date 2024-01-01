#include <cmath>
#include <iostream>

int main()
{
    int x { 7 };
    int y { 4 };
    double pow { std::pow(3.0, 4.0) };

    std::cout << x / y << '\n';

    std::cout << static_cast<double>(x) / y << '\n';

    std::cout << pow << '\n';

    return 0;
}
