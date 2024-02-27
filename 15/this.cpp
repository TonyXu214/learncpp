#include <iostream>

class Foo
{
private:
    int m_x {};

public:
    Foo() = default;
    Foo(int x)
        : m_x { x }
    {
    }

    Foo& add(int x)
    {
        m_x += x;
        return *this;
    }

    Foo& multiply(int x)
    {
        m_x *= x;
        return *this;
    }

    void print()
    {
        std::cout << this->m_x << '\n';
    }

    void reset()
    {
        *this = {};
    }
};

int main()
{
    Foo f { 5 };
    f.print();
    f.multiply(6).add(1);
    f.print();
    f.reset();
    f.print();

    return 0;
}

