#include <iostream>

namespace {
    int doSomething()
    {
        return 5;
    }
}

int main()
{
    std::cout << doSomething() << '\n';

    return 0;
}
