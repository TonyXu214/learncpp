#include <iostream>

void iter(int x)
{
    if (x <= 0)
        return;

    std::cout << x << '\n';
    iter(x-1);
}

int main()
{
    iter(5);
    return 0;
}

