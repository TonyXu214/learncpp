#include <iostream>

int main()
{
    int x { 5 };
    void* ptr { &x };
    std::cout << ptr << '\n';
    std::cout << *static_cast<int*>(ptr) << '\n';

    return 0;
}
