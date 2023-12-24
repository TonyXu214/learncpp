#include <iostream>

int main()
{
    int x { 2'147'483'647 };

    int y { x + 1 };

    std::cout << x << std::endl;
    std::cout << y << std::endl;

    return 0;
}
