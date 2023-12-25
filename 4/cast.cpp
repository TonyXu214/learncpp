#include <cstdint>
#include <iostream>

void print(int x)
{
    std::cout << x << '\n';
}

int main()
{
    // std::int8_t x { 65 };
    // std::cout << static_cast<int>(x) << '\n';
    // unsigned int x { 7 };
    // int s { static_cast<int>(x) };

    // std::cout << s << '\n';
    // double y{ 5.0 };
    // int y{ 5 };
    //
    // print(y);
    // print(static_cast<int>(5.6));
    // char b { 97 };

    // std::cout << static_cast<int>(b) << '\n';
    std::int8_t x {};

    std::cin >> x;

    // std::cout << static_cast<int>(x) << '\n';
    print(x);

    return 0;
}
