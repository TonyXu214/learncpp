#include <iostream>

void scope(int x)
{
    switch (x)
    {
        int a; // okay, definition is allowed
        int b { 5 }; // illegal, initialization not allowed

        case 1:
            int y; // okay, definition is allowed
            y = 5; // okay, assignment is allowed
            break;
        case 2:
            int x { 5 }; // illegal, initialization not allowed if subsequent
            y = 7; // okay, y was declared above
            break;
        default:
            ;
    }
}

void printStuff(int x)
{
    switch (x)
    {
        case 1:
            std::cout << '1' << '\n';
            break;
        case 2:
            std::cout << '2' << '\n';
            [[fallthrough]];
        case 3:
            std::cout << '3' << '\n';
        default:
            std::cout << "Unknown" << '\n';
            break;
    }

    std::cout << "asdf" << '\n';
}

int main()
{
    printStuff(2);

    return 0;
}
