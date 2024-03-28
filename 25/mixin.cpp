#include <iostream>

class Mixin
{
private:
    int m_x {};

public:
    void set_x(int x)
    {
        m_x = x;
    }

    int get_x()
    {
        return m_x;
    }
};

class Derived: public Mixin
{
};

int main()
{
    Derived d;
    d.Mixin::set_x(5);
    std::cout << d.Mixin::get_x() << '\n';

    return 0;
}

