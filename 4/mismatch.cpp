#include <iostream>

int main()
{
    signed int s { -1 };
    unsigned int u { 1 };

    if (s < u)
        std::cout << "s: " << s << std::endl;
    else
        std::cout << "u: " << u << std::endl;

    return 0;
}
