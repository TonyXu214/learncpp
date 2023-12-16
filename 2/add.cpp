#include <iostream>

int add(int x, int y)
{
#ifdef PRINTING
    std::cout << "printing" << std::endl;
#endif

#ifndef PRINTING
    std::cout << "not printing" << std::endl;
#endif

    return x + y;
}
