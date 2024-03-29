#include <iostream>

class Base
{
private:
    int m_x {};

public:
    Base (int x) : m_x { x }
    {
    }
};

class Derived: public Base
{
private:
    int m_y {};

public:
    Derived(int x=1, int y=2)
        : Base(x)
        , m_y { y }
    {
    }
};

int main()
{
    return 0;
}
