#include <functional>
#include <iostream>

using FuncPtr = void(*)();
void foo()
{
    std::cout << 5 << '\n';
}

void goo()
{
    std::cout << 6 << '\n';
}

void poo(void (*moo)() = foo)
{
    moo();
}

void loo(FuncPtr foo)
{
    foo();
}

int boo(int x)
{
    return x;
}

int main()
{
    void (*ptr)() { &foo };
    (*ptr)(); // explicitly dereference

    ptr = goo; // implicit conversion to memory address done
    ptr(); // implicitly dereference

    poo(ptr);
    poo(); // uses default

    FuncPtr zoo { &foo };
    zoo();

    loo(&goo);

    std::function<int(int)> fcn { &boo };
    std::cout << fcn(8) << '\n';

    std::function fcn2 { &boo };
    std::cout << fcn2(9) << '\n'; // using CTAD

    auto coo { &foo };
    coo();

    return 0;
}
