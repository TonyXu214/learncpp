#include <iostream>

class Foo
{
private:
    int m_x {};

public:
    // Default constructor
    Foo()
    {
        std::cout << "Foo default initialized" << '\n';
    }

    // Normal contructor
    Foo(int x)
        : m_x { x }
    {
        std::cout << "Foo value initialized" << '\n';
    }

    // copy constructor
    Foo(const Foo& foo)
    {
        std::cout << "Foo copy initialized" << '\n';
    }
};

int main()
{
    // calls default constructor
    Foo f; // default initialization
    Foo f1 {}; // value initialized

    // calls Foo(int) normal contructor
    Foo f3 = 1; // copy initialization
    Foo f5 = { 1 }; // copy list initialization
    Foo f4(4); // direct initialization
    Foo f2 { 1 }; // direct list initialization

    // call Foo(const Foo&) constructor
    Foo f7 = f1; // copy initialization
    Foo f8(f7); // direct initialization
    Foo f9 { f8 }; // direct list initialization
    Foo f10 = { f9 }; // copy list initialization

    return 0;
}

