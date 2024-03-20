#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents) : m_cents { cents }
    {
    }

    friend Cents operator+(const Cents& c1, const Cents& c2);
    friend Cents operator+(const Cents& c1, int x);
    friend Cents operator+(int x, const Cents& c1);

    int getCents()
    {
        return m_cents;
    }
};

Cents operator+(const Cents& c1, const Cents& c2)
{
    return c1.m_cents + c2.m_cents;
}

Cents operator+(const Cents& c1, int x)
{
    return c1.m_cents + x;
}

Cents operator+(int x, const Cents& c1)
{
    return c1 + x;
}

int main()
{
    Cents cents1 { 5 };
    std::cout << cents1.getCents() << '\n';

    Cents cents2 { 6 };
    std::cout << cents2.getCents() << '\n';

    std::cout << (cents1 + cents2).getCents() << '\n';
    std::cout << (cents1 + 4).getCents() << '\n';
    std::cout << (10 + cents1).getCents() << '\n';

    return 0;
}

