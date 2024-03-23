#include <iostream>

class Functor
{
private:
    int m_x { 0 };

public:
    Functor() = default;

    int operator()(int x);
};

int Functor::operator()(int x)
{
    m_x += x;
    return m_x;
}

int main()
{
    Functor f {};
    std::cout << f(4) << '\n';
    std::cout << f(3) << '\n';

    return 0;
}

