#include <iostream>

int main()
{
    // unsigned short x{ 65535 }; // largest unsigned 16-bit value possible
    // std::cout << "x was: " << x << std::endl;
    //
    // x = 65536;
    // std::cout << "x is now: " << x << std::endl;
    //
    // x = 65537;
    // std::cout << "x is now: " << x << std::endl;

    unsigned short x{ 0 }; // largest unsigned 16-bit value possible
    std::cout << "x was: " << x << std::endl;

    x = -1;
    std::cout << "x is now: " << x << std::endl;

    x = -2;
    std::cout << "x is now: " << x << std::endl;
    return 0;
}

