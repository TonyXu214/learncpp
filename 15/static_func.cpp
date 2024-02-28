#include <iostream>

class Foo
{
private:
    static constexpr int m_x { 10 };
    static inline int m_y { 9 };

public:
    Foo() = default;

    static constexpr int get_x()
    {
        return m_x;
    }

    static int get_y();
};

int Foo::get_y()
{
    return m_y;
}

int main()
{
    std::cout << Foo::get_x() << '\n';
    std::cout << Foo::get_y() << '\n';
    return 0;
}
