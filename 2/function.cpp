#include "test.h"
#include "square.h"
#include <iostream>

#define LIGMA "balls"
#define PRINTING
// #define PRINT_MY_BALLS

// using namespace std;

int add(int x, int y);
int getInput();
int getSquareSides();

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

    std::cout << getArea(5) << std::endl;
    // int x { getInput() };
    // std::cout << LIGMA << std::endl;
    // std::cout << add(1, 2) << std::endl;

// #ifdef LIGMA_BALLLLLLS
    // std::cout << "test" << std::endl;
// #endif
//
// #ifndef PRINT_MY_BALLS
//     std::cout << "my " << LIGMA << std::endl;
// #endif
    return 0;
}

// int add(int x, int y)
// {
//     return x + y;
// }
