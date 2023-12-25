#include <iostream>

int main()
{
    int x { 8 };
    int y { 5 };

    unsigned int u_x { 8 };
    unsigned int u_y { 5 };

    std::cout << x / y << std::endl;
    std::cout << u_x / u_y << std::endl;

    return 0;
}
