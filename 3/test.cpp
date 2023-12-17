#include <iostream>

// #define DEBUG

int getValue()
{
#ifdef DEBUG
std::cerr << "getValue() called\n";
#endif
    return 1;
}

int main()
{
#ifdef DEBUG
std::cerr << "main() called" << std::endl;
#endif
    std::cout << getValue << std::endl;
    return 0;
}

