#include <iostream>

void printC(bool b)
{
    if (b)
    {
        goto print;
    }

    std::cout << "not in goto" << '\n';
    int x { 5 }; // initialized variable still in scope at label print

print:
    std::cout << "in goto" << '\n';
    x += 3; // what would this evaluate to if x wasn't initialized
}

int main()
{
    int x {};
tryAgain:
    std::cout << "Enter a positive number" << '\n';
    std::cin >> x;

    if (x <= 0)
    {
        goto tryAgain;
    }

    std::cout << "you entered: " << x << '\n';

    std::cout << "false case" << '\n';
    printC(false);

    std::cout << "true case" << '\n';
    printC(true);

    return 0;
}
