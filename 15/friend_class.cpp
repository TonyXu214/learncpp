#include <iostream>

class Foo;

class Bar
{
public:
    void print(const Foo& f);
};

class Foo
{
private:
    int m_x {};

public:
    Foo() = delete;
    Foo(int x) : m_x { x }
    {
    }

    // friend class Bar;
    friend void Bar::print(const Foo& f);
};

void Bar::print(const Foo& f)
{
    std::cout << f.m_x << '\n';
}

int main()
{
    Foo f { 5 };
    Bar b {};
    b.print(f);

    return 0;
}

