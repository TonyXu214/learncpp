#include <iostream>
#include <string_view>

void nullify(int*& tonull)
{
    tonull = nullptr;
}

void greet(std::string_view name)
{
    std::cout << name << '\n';
}

void greet()
{
    std::cout << "guest" << '\n';
}

// void changeVal(const int* x)
// {
//     *x = 7;
// }

void changeVal(int* x)
{
    *x = 7;
}

int main()
{
    int x { 5 };
    int* p_x { &x };
    std::cout << *p_x << '\n';
    int y { 6 };
    p_x = &y;
    std::cout << *p_x << '\n';
    *p_x = 7;

    std::cout << y << '\n';
    std::cout << *p_x << '\n';

    {
        int z { 6 };
        p_x = &z;

        std::cout << *p_x << '\n';
    }

    std::cout << *p_x << '\n'; // dangling pointer

    // int* null {}; // value initialize for nullptr

    // std::cout << *null << '\n'; // crashes program, dereferencing nullptr
    // int* null2 { nullptr }; // nullptr literal

    const int c { 10 };
    // int* z { &c }; // won't compile
    const int* z { &c };
    std::cout << *z << '\n';

    const int c1 { 11 };
    z = &c1;
    std::cout << *z << '\n';

    int c2 { 12 };
    z = &c2;
    std::cout << *z << '\n';
    // *z = 13; // compile error

    int* const ptr { &x };
    std::cout << *ptr << '\n';
    // ptr = &y; // compile error, const ptr
    *ptr = 20;
    std::cout << x << '\n';
    std::cout << *ptr << '\n';

    changeVal(&x); // compile error, changeVal takes const int*
    std::cout << x << '\n';

    greet();
    greet("Tony");

    int* tonull { &x };
    std::cout << *tonull << '\n';
    nullify(tonull);
    std::cout << (tonull ? *tonull : 9999) << '\n';
    return 0;
}
