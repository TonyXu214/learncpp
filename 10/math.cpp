#include <iostream>
#include <typeinfo>

int main()
{
    int i { 2 };
    double d { 3.5 };

    std::cout << typeid(1).name() << " " << i + d << '\n';
    std::cout << typeid(i + d).name() << " " << i + d << '\n';

    return 0;
}
