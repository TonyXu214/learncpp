#include <iostream>

double getDouble()
{
    double x {};
    std::cout << "Please pass in a double\n";
    std::cin >> x;

    return x;
}

char getChar()
{
    char x {};
    std::cout << "Enter +, -, *, or /\n";
    std::cin >> x;

    return x;
}

void compute(double x, double y, char op)
{
    if (op == '+')
        std::cout << x + y << '\n';
    else if (op == '-')
        std::cout << x - y << '\n';
    else if (op == '*')
        std::cout << x * y << '\n';
    else if (op == '/')
        std::cout << x / y << '\n';
}

int main()
{
    double x { getDouble() };
    double y { getDouble() };
    char op { getChar() };

    compute(x, y, op);

    return 0;
}
