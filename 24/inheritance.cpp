#include <iostream>

class Foo
{
protected:
    int m_x {};

public:

    Foo() : m_x { 10 }
    {
        std::cout << "Default Foo" << '\n';
    }

    Foo(int x) : m_x { x }
    {
        std::cout << "Instantiating Foo" << '\n';
    }

    void fooOut()
    {
        std::cout << m_x << '\n';
    }
};

class Bar : public Foo
{
private:
    int m_y {};

public:

    Bar(int y=0, int x=10)
        : Foo { 10 }
        , m_y { y }
    {
        std::cout << "Instantiating Bar" << '\n';
    }

    void barOut()
    {
        std::cout << m_x << m_y << '\n';
    }
};

int main()
{
    Bar b;
    b.fooOut();
    b.barOut();
    return 0;
}
