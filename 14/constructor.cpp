#include <iostream>

class Foo
{
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y) : m_x { x }, m_y { y }
    {
        std::cout << "constructed!" << '\n';
    }

    void print()
    {
        std::cout << m_x << m_y << '\n';
    }
};

int main()
{
    Foo f { 1, 2 };
    f.print();

    return 0;
}
