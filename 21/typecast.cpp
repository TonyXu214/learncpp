#include <iostream>

class Foo
{
private:
    int m_x {};

public:
    Foo(int x) : m_x { x }
    {
    }

    explicit operator int() const
    {
        return m_x;
    }

    int getX() const
    {
        return m_x;
    }
};

void printInt(int x)
{
    std::cout << x << '\n';
}

int main()
{
    Foo f { 10 };
    std::cout << f.getX() << '\n';
    // printInt(f);
    std::cout << static_cast<int>(f) << '\n';
    // std::cout << f << '\n';

    return 0;
}

