#include <iostream>

void increment()
{
    static int s_value { 1 }; // static duration, initiazlizer only once
    ++s_value;
    std::cout << s_value << '\n';
} // s_value not destroyed but not accessible b/c out of scope

int main()
{
    increment();
    increment();
    increment();

    return 0;
}
