#include <iostream>

int main()
{
    // write a function that takes an int and prints it to the screen
    // call the function with the following types of initialization
    // and observe the output

    int print(int x)
    {
        std::cout << x << std::endl;
    }

    // default initialization
    int a;

    // copy initialization
    int b = 5;

    // direct initialization
    int c(6);

    // direct list initialization
    int d {7};

    // copy list initialization
    int e = {8};

    // value initialization
    int f {};

    return 0;
}
