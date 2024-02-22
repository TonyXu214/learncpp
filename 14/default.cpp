#include <iostream>

class User
{
private:
    int m_x;
    int m_y {};

public:
    User() {}

    int x() const { return m_x; }
    int y() const { return m_y; }

};

class Default
{
private:
    int m_x;
    int m_y {};

public:
    Default() = default;
    int x() const { return m_x; }
    int y() const { return m_y; }
};

class Implicit
{
private:
    int m_x;
    int m_y {};

public:
    int x() const { return m_x; }
    int y() const { return m_y; }
};

class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo() = default;

    Foo(int x, int y)
        : m_x { x }
        , m_y { y }
    {
        std::cout << m_x << m_y << '\n';
    }
};

int main()
{
    Foo f {};
    Foo g;

    Foo one { 1, 2 };

    User u {};
    std::cout << u.x() << u.y() << '\n';
    Default d {};
    std::cout << d.x() << d.y() << '\n';
    Implicit i {};
    std::cout << i.x() << i.y() << '\n';

    return 0;
}

