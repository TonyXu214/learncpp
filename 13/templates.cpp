#include <iostream>
#include <utility>

template <typename T>
struct Foo
{
    T x {};
    T y {};
};

template <typename T, typename U>
struct Bar
{
    T x {};
    U y {};
};

// template <typename T, typename U>
// void printBar(Bar<T, U> b)
// {
//     std::cout << b.x << b.y << '\n';
// }

template <typename T, typename U>
void printBar(std::pair<T, U> p)
{
    std::cout << p.first << p.second << '\n';
}

template <typename T>
void printBar(T b)
{
    std::cout << b.x << b.y << '\n';
}

template <typename T>
T print(Foo<T> p)
{
    std::cout << p.x << p.y << '\n';
    return p.x;
}

int main()
{
    Foo<int> f { 1, 2 };
    std::cout << f.x << f.y << '\n';
    std::cout << print(f) << '\n';

    Bar<int, double> b { 1, 2.5 };
    printBar(b);

    std::pair<double, int> p { 3.14, 1 };
    printBar(p);

    return 0;
}
