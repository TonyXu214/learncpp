#include <cassert>
#include <cmath>
#include <iostream>

// template <double D>
// double getSqrt()
// {
//     static_assert(D >= 0 && "getSqrt(): d must be non-negtive");
//
//     if constexpr (D >= 0)
//         return std::sqrt(D);
//
//     return 0.0;
// }
//
// // double getSqrt(double d)
// // {
// //     assert(d >= 0 && "getSqrt(): d must be non-negative");
// //
// //     if (d >= 0)
// //         return std::sqrt(d);
// //
// //     return 0.0;
// // }
//
// template <int N>
// void printN()
// {
//     std::cout << N << '\n';
// }
//
// int main()
// {
//     printN<8>();
//
//     std::cout << getSqrt<5.0>() << '\n';
//     // std::cout << getSqrt<-5.0>() << '\n';
//
//     return 0;
// }
template <double D> // requires C++20 for floating point non-type parameters
double getSqrt()
{
    // static_assert(D >= 0.0, "getSqrt(): D must be non-negative");

    // if constexpr (D >= 0) // ignore the constexpr here for this example
    //     return std::sqrt(D); // strangely, std::sqrt isn't a constexpr function (until C++26)

    return D;
}

int main()
{
    std::cout << getSqrt<5.0>() << '\n';
    // std::cout << getSqrt<-5.0>() << '\n';

    return 0;
}
