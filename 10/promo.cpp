#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    printInt(2);

    short s { 3 };
    printInt(s);

    printInt('a');
    printInt(true);

    return 0;
}

