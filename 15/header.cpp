#include "header.hpp"

#include <iostream>

Foo::Foo(int x)
    : m_x { x }
{
}

void Foo::print() const
{
    std::cout << m_x << '\n';
}

int main()
{
    Foo f { 5 };
    f.print();

    return 0;
}

