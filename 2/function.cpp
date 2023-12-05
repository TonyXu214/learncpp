#include <iostream>

int doReturnInput()
{
    int x{};

    std::cin >> x;

    return x;
}

void doPrint(int x)
{
    std::cout << x << std::endl;
}

void return5()
{
    return 5;
}

int main()
{
    int x { doReturnInput() };

    doPrint(x);

    std::cout << return5() << std::endl;

    return 0;
}
