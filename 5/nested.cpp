#include <iostream>

constexpr int goo(int b)
{
    return b;
}

constexpr int foo(int b)
{
    // constexpr int b2 { b }; // compile error: b is not a constant expression within foo()

    return goo(b);
}

int main()
{
    constexpr int x { 5 };

    std::cout << foo(x) << '\n';

    return 0;
}
