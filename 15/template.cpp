#include <iostream>

template <typename T>
class Foo
{
private:
    T m_x {};

public:
    Foo(const T& x)
        : m_x { x }
    {
    }

    void print()
    {
        std::cout << m_x << '\n';
    }

    T get_x();
};

template <typename T>
T Foo<T>::get_x()
{
    return m_x;
}

int main()
{
    Foo f { 1 };
    f.print();
    std::cout << f.get_x() << '\n';

    return 0;
}

