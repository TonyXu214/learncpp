#include <iostream>

class Foo
{
private:
    int m_x {};

public:
    Foo(int x)
        : m_x { x }
    {
        std::cout << "Initialized" << '\n';
    }

    void print()
    {
        std::cout << m_x << '\n';
    }

    ~Foo()
    {
        std::cout << m_x << " destructed" << '\n';
    }
};

int main()
{
    Foo foo { 5 };
    foo.print();

    Foo* foo2 { new Foo { 6 } };
    foo2->print();
    delete foo2;

    return 0;
}
