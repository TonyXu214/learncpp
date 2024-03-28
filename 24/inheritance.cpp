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

    void identity() const
    {
        std::cout << "I am FOO" << '\n';
    }

    friend std::ostream& operator<<(std::ostream& s, const Foo& f)
    {
        s << f.m_x;
        return s;
    }

protected:
    void print_val() const
    {
        std::cout << m_x << '\n';
    }
};

class Baz
{
private:
    int m_z {};

public:
    Baz(int z) : m_z { z }
    {
        std::cout << "Instantiating Baz" << '\n';
    }

    void print()
    {
        std::cout << m_z << '\n';
    }
};

class Bar : public Foo, public Baz
{
private:
    int m_y {};

public:

    Bar(int y=0, int x=10)
        : Foo { y }
        , Baz { x }
        , m_y { y }
    {
        std::cout << "Instantiating Bar" << '\n';
    }

    void barOut()
    {
        std::cout << m_x << m_y << '\n';
    }

    friend std::ostream& operator<<(std::ostream& s, const Bar& b)
    {
        s << static_cast<const Foo&>(b);
        return s;
    }

    void identity() const
    {
        Foo::identity();
        std::cout << "I am BAR" << '\n';
    }

    using Foo::print_val;
    // void print() const
    // {
    //     print_val();
    // }
};

int main()
{
    Bar b { 5 };
    b.print_val();
    b.fooOut();
    b.barOut();
    b.identity();

    Foo f { 10 };
    f.identity();

    std::cout << b << '\n';
    std::cout << f << '\n';

    return 0;
}
