#include <iomanip>
#include <iostream>

int main()
{
    // int x{5};      // 5 means integer
    // double y{5.0}; // 5.0 is a floating point literal (no suffix means double type by default)
    // float z{5.0f}; // 5.0 is a floating point literal, f suffix means float type

    std::cout << std::setprecision(17);
    std::cout << 5.0 << '\n';
	std::cout << 6.7f << '\n';
	std::cout << 9876543.21 << '\n';
    std::cout << 9.87654321f << '\n';
    std::cout << 987.654321f << '\n';
    std::cout << 987654.321f << '\n';
    std::cout << 9876543.21f << '\n';
    std::cout << 0.0000987654321f << '\n';
    std::cout << 3.33333333333333333333333333333333333333f <<'\n'; // f suffix means float
    std::cout << 3.33333333333333333333333333333333333333 << '\n'; // no suffix means double

    float f { 123456789.0f }; // f has 10 sig figs
    std::cout << std::setprecision(9); // to show 9 digits in f
    std::cout << f << '\n';

    double d {0.1};
    std::cout << std::setprecision(6);
    std::cout << d << std::endl;
    std::cout << std::setprecision(17);
    std::cout << d << std::endl;

    double one {1.0};
    std::cout << std::setprecision(17);
    std::cout << one << std::endl;
    double d2{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 }; // should equal 1.0
    std::cout << d2 << '\n';

    double zero { 0.0 };
    double posinf { 5.0 / zero };
    std::cout << posinf << std::endl;

    double neginf { -5.0 / zero };
    std::cout << neginf << std::endl;

    double nan { zero / zero };
    std::cout << nan << std::endl;

    return 0;
}
