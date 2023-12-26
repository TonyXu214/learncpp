#include <iostream>

void someFcn()
{
// Even though gravity is defined inside this function
// the preprocessor will replace all subsequent occurrences of gravity in the rest of the file
#define gravity 9.8
}

void printGravity(double gravity) // including this one, causing a compilation error
{
    std::cout << "gravity: " << gravity << '\n';
}

int main()
{
    double x { 99.0 };
    const double y { x };

    printGravity(9.0);

    std::cout << y << '\n';


    return 0;
}
