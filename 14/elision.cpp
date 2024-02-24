#include <iostream>

class Foo
{
private:
    int m_x {};

public:
    Foo(int x)
        : m_x { x }
    {
        std::cout << "Foo normally constructed" << '\n';
    }

    Foo(const Foo& f)
        : m_x { f.m_x }
    {
        std::cout << "Foo copy constructed" << '\n';
    }

    void print()
    {
        std::cout << m_x << '\n';
    }
};

int main()
{
    Foo f { Foo { 5 } };
    f.print();

    return 0;
}

