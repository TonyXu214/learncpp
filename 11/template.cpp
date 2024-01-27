#include "add_template.hpp"

#include <iostream>

// template <typename T>
// T add(T x, T y);

template <typename T>
T addOne(T x)
{
    return x + 1;
}

template <typename T>
void print(T x)
{
    std::cout << x << '\n';
}

void print(bool x)
{
    std::cout << std::boolalpha << x << '\n';
}

template <typename T>
T max(T x, T y)
{
    return (x > y) ? x : y;
}

template <>
const char* addOne(const char* x) = delete;

int main()
{
    std::cout << max<int>(5, 10) << '\n';
    std::cout << max<>(5, 10) << '\n'; //  the compiler will only consider max<int> template function overloads
    std::cout << max(5, 10) << '\n'; // the compiler will consider both max<int> template function overloads and max non-template function overloads
    std::cout << max<int>('a', 'b') << '\n';
    std::cout << max<char>('a', 'b') << '\n';
    print<bool>(true); // matches to template
    print<>(true); // matches to template
    print(true); // matches to non template

    std::cout << addOne<int>(3) << '\n';
    std::cout << addOne(3) << '\n';
    std::cout << addOne<double>(4.3) << '\n';
    std::cout << addOne(4.3) << '\n';
    std::string hello {"hello"};
    // std::cout << addOne(hello) << '\n'; // does not compile
    //
    // std::cout << addOne("hello") << '\n'; // deleted

    std::cout << add<int>(1, 2) << '\n'; // does not link, add.cpp unit has no instantiations for int
    return 0;
}
