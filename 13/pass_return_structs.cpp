#include <iostream>

struct Foo
{
    int x {};
    int y {};
    int z {};
};

void printFoo(const Foo& foo)
{
    std::cout << foo.x << foo.y << foo.z << '\n';
}

Foo returnFoo()
{
    Foo temp { 1, 2, 3 };
    return temp;
}

// return temporary object
Foo betterReturnFoo()
{
    return Foo { 1, 2, 3 }; // Foo is constructed, copied back to caller, then destroyed
}

Foo bestReturnFoo()
{
    return { 1, 2, 3 };
}

int main()
{
    printFoo(returnFoo());
    printFoo(betterReturnFoo());
    printFoo(bestReturnFoo());

    return 0;
}
