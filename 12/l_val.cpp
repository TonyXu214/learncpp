#include <iostream>

#define isSmall(T) (sizeof(T) <= 2 * sizeof(void*))
// void add(const int& y) // compile error
// {
//     ++y;
// }

void add(int& y) // compile error
{
    ++y;
}

struct S
{
    double a;
    double b;
    double c;
};

int main()
{
    // int& j; // compile error must be initialized
    const int z { 8 };
    // int& l { z }; // compile error, z is const
    const int& l { z }; // not compile error, z is const
    std::cout << l << '\n';
    int x { 5 };
    int& y { x };

    std::cout << x << y << '\n';

    x = 6;

    std::cout << x << y << '\n';

    y = 7;

    std::cout << x << y << '\n';

    int yy { 1 };
    const int& xx { yy };
    std::cout << xx << yy << '\n';

    // xx = 2; // compile error, xx is l-value reference to const

    const int& r { 7 };

    std::cout << r << '\n'; // reference to const bound to temporary object

    int add_1 { 1 };
    std::cout << add_1 << '\n';
    add(add_1);
    std::cout << add_1 << '\n';

    std::cout << isSmall(int) << '\n'; // true
    std::cout << isSmall(double) << '\n'; // true
    std::cout << isSmall(S) << '\n'; // false
    return 0;
}
