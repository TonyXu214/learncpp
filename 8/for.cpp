#include <iostream>

void fizzbuzz(int x)
{
    for (int i { 1 }; i <= x; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            std::cout << "fizzbuzz" << '\n';
        else if (i % 3 == 0)
            std::cout << "fizz" << '\n';
        else if (i % 5 == 0)
            std::cout << "buzz" << '\n';
        else
            std::cout << i << '\n';
    }
}

int sumTo(int x)
{
    int i { 0 };
    int sum { 0 };

    while (i <= x)
    {
        sum += i;
        ++i;
    }

    return sum;
}

void print20()
{
    for (int i { 0 }; i <= 20; ++i)
        std::cout << i << '\n';
}

int main()
{
    print20();
    std::cout << sumTo(5) << '\n';
    fizzbuzz(15);

    return 0;
}
