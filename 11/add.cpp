#include <iostream>

int add(int x, int y)
{
    return x + y;
}

double add(double x, double y)
{
    return x + y;
}

int main()
{
    // double d_x { 5.0 };
    // double d_y { 4.0 };
    //
    // int x { 5 };
    // int y { 4 };

    std::cout << add(1, 2) << '\n';
    std::cout << add(1.2, 1.3) << '\n';

    return 0;
}

