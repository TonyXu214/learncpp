#include <iostream>

class Base
{
private:
    int m_x {};

public:
    Base(int x) : m_x { x }
    {
    }

    int get_int() const
    {
        return m_x;
    }

    virtual void whoami() const
    {
        std::cout << "Base" << '\n';
    }
};

class Derived : public Base
{
private:
    int m_y {};

public:
    Derived(int x=0, int y=1)
        : Base(x)
        , m_y { y }
    {
    }

    int get_int() const
    {
        return m_y;
    }

    void whoami() const override
    {
        std::cout << "Derived" << '\n';
    }
};

int main()
{
    Derived d;
    Base& b { d };
    std::cout << d.get_int() << '\n';
    std::cout << b.get_int() << '\n';
    d.whoami();
    b.whoami();

    return 0;
}
