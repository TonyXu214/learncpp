#include <iostream>

constexpr int add(int x, int y)
{
    return x + y;
}

int main()
{
    int x { 5 };
    int y { ++x };

    std::cout << x << ' ' << y << '\n';

    int a { 9 };
    int b { a++ };

    std::cout << a << ' ' << b << '\n';

    int bad { 1 };

    // undefined, which arg is evaluated first?
    std::cout << add(bad, ++bad) << '\n';

    return 0;
}
