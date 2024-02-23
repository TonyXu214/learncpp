#include <iostream>

struct Foo
{
private:
    int m_x {};

public:
    Foo(int x)
        : m_x { x }
    {
    }

    // Foo(const Foo& f)
    //     : m_x { f.m_x }
    // {
    //     std::cout << "copy constructor called" << '\n';
    // }

    // Foo(const Foo& f) = default;
    Foo(const Foo& f) = delete;

    void print()
    {
        std::cout << m_x << '\n';
    }
};

void printFoo(Foo f)
{
    f.print();
}

Foo generateFoo()
{
    Foo f { 1 };
    return f;
}

int main()
{
    Foo f { generateFoo() };
    printFoo(f);

    return 0;
}
