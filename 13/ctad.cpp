#include <iostream>

template <typename T=int, typename U=int>
struct Foo
{
    T x;
    T y;

    std::pair p2 { 1, 2 }; // non-static member initialization, compile error
};

// void printPair(std::pair x) // compile-error
// {
//     std::cout << x.first << '\n';
// }

template <typename T, typename U>
void printPair(std::pair<T, U> x) // this should be used instead
{
    std::cout << x.first << '\n';
}

int main()
{
    // std::pair<> p { 1, 2 }; // error
    // std::pair<int> p { 1, 2 }; // error
    std::pair p { 1, 2 }; // ctad to deduce std::pair<int, int>
    std::cout << p.first << p.second << '\n';

    Foo f; // gets int, int
    return 0;
}

