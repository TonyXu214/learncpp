#include <iostream>

void getX(int& x) // x is an out parameter
{
    x = 10;
}

void print(int x) // x is an in parameter
{
    std::cout << x << '\n';
}

int main()
{
    int x { };
    getX(x);

    std::cout << x << '\n';

    print(0);

    return 0;
}
