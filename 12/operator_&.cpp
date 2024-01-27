#include <iostream>

int main()
{
    int x { 5 };
    std::cout << &x << '\n';
    std::cout << &5 << '\n'; // can't take address of r-value

    return 0;
}

