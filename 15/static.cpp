#include <iostream>

struct Foo
{
    static int x;
    static const int y { 5 };
    static inline int z { 10 };
    static constexpr std::string_view s_view { "ello" };
};

class Bar
{
private:
    static inline int id { 1 };
    int m_id {};

public:
    Bar() : m_id { id++ }
    {
    }

    void print()
    {
        std::cout << m_id << '\n';
    }
};

int Foo::x{ 1 };

int main()
{
    Bar b1 {};
    b1.print();
    Bar b2 {};
    b2.print();

    // Foo f {};
    // Foo g {};
    // std::cout << f.x << '\n';
    // std::cout << g.x << '\n';
    //
    // g.x = 5;
    // std::cout << f.x << '\n';
    // std::cout << g.x << '\n';

    std::cout << Foo::x << '\n';
    std::cout << Foo::y << '\n';
    std::cout << Foo::z << '\n';
    std::cout << Foo::s_view << '\n';

    return 0;
}

