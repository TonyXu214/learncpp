#include "fraction.hpp"
#include <iostream>

int main()
{
    Fraction f { 1, 2 };

    std::cout << f.numerator << f.denominator << '\n';

    return 0;
}
