#include <iostream>

int add(int x, int y);

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

// void return5()
// {
//     return 5;
// }

int doubleNumber(int x)
{
    return x * 2;
}

int userInput()
{
    int x{};

    std::cin >> x;

    return x;
}

int add2(int x, int y)
{
    return x + y;
}

int getUserInput()
{
    int x{};
    int y{};

    std::cin >> x;

    std::cin >> y;

    return add2(x, y);
}

int main()
{

    std::cout << add(1, 2) << std::endl;
    return 0;
}

// int add(int x, int y)
// {
//     return x + y;
// }
