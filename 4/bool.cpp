#include <iostream>

bool isEqual(int x, int y)
{
    return x == y;
}

int main()
{
    bool b { !false };
    bool a { !true };

    std::cout << std::boolalpha;
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << std::noboolalpha;

    // bool zero { 0 };
    // bool one { 1 };
    // bool two { 2 }; // error no narrowing conversions allowed

    bool x = 4;
    bool y = 0;

    std::cout << std::boolalpha;
    std::cout << x << std::endl;
    std::cout << y << std::endl;

    bool in {};

    std::cin >> in;

    std::cout << in << std::endl;

    std::cout << isEqual(5, 5) << std::endl;
    std::cout << isEqual(6, 5) << std::endl;

    return 0;
}
