#include <iostream>

int main()
{
    constexpr int n1 { 5 };
    unsigned int u1 { n1 };

    std::cout << u1 << '\n';

    constexpr int n2 { -5 };
    unsigned int u2 { n2 };

    std::cout << u2 << '\n';

    return 0;
}
