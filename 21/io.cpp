#include <iostream>

class Foo
{
private:
    int m_x {};
    int m_y {};
    int m_z {};

public:
    Foo(int x, int y, int z)
        : m_x { x }
        , m_y { y }
        , m_z { z }
    {
    }

    friend std::ostream& operator<<(std::ostream& stream, const Foo& foo);
    friend std::istream& operator>>(std::istream& stream, Foo& foo);
};

std::ostream& operator<<(std::ostream& stream, const Foo& foo)
{
    stream << foo.m_x << foo.m_y << foo.m_z;
    return stream;
}

std::istream& operator>>(std::istream& stream, Foo& foo)
{
    stream >> foo.m_x;
    stream >> foo.m_y;
    stream >> foo.m_z;

    return stream;
}

int main()
{
    Foo foo { 4, 6, 9 };
    std::cout << foo << '\n';

    std::cin >> foo;
    std::cout << foo << '\n';

    return 0;
}

