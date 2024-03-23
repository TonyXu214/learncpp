#include <iostream>

class Cents
{
private:
    int m_cents {};

public:
    Cents(int cents) : m_cents { cents }
    {
    }

    // friend Cents operator+(const Cents& c1, const Cents& c2);
    friend Cents operator+(const Cents& c1, int x);
    friend Cents operator+(int x, const Cents& c1);
    friend bool operator==(const Cents& c1, const Cents& c2);

    Cents operator-() const;
    bool operator!() const;
    int getCents() const
    {
        return m_cents;
    }
};

bool operator==(const Cents& c1, const Cents& c2)
{
    return c1.m_cents == c2.m_cents;
}

bool Cents::operator!() const
{
    return m_cents == 0;
}

Cents Cents::operator-() const
{
    return -m_cents;
}

// Cents operator+(const Cents& c1, const Cents& c2)
// {
//     return c1.m_cents + c2.m_cents;
// }

Cents operator+(const Cents& c1, int x)
{
    return c1.m_cents + x;
}

Cents operator+(int x, const Cents& c1)
{
    return c1 + x;
}

Cents operator+(const Cents& c1, const Cents& c2)
{
    return c1.getCents() + c2.getCents();
}

int main()
{
    Cents c { 0 };
    std::cout << std::boolalpha;
    std::cout << !c << '\n';

    Cents cents1 { 5 };
    std::cout << cents1.getCents() << '\n';

    Cents cents2 { 6 };
    std::cout << cents2.getCents() << '\n';

    std::cout << (cents1 + cents2).getCents() << '\n';
    std::cout << (cents1 + 4).getCents() << '\n';
    std::cout << (10 + cents1).getCents() << '\n';
    std::cout << (-cents2).getCents() << '\n';

    Cents cents3 { 5 };
    std::cout << (cents1 == cents3) << '\n';
    std::cout << (cents2 == cents3) << '\n';

    return 0;
}

