#include <iostream>

class Friend2; // needed for isEqual

class Friend
{
private:
    int m_x {};

public:
    Friend() = delete;
    Friend(int x) : m_x { x }
    {
    }

    friend void print(const Friend& f);
    friend bool isEqual(const Friend& f, const Friend2& g); // reason for forward declaration
};

class Friend2
{
private:
    int m_x {};

public:
    Friend2() = delete;
    Friend2(int x) : m_x { x }
    {
    }

    friend bool isEqual(const Friend& f, const Friend2& g);
};

bool isEqual(const Friend& f, const Friend2& g)
{
    return f.m_x == g.m_x;
}

void print(const Friend& f)
{
    std::cout << f.m_x << '\n';
}

int main()
{
    Friend f { 5 };
    print(f);
    Friend2 f2 { 5 };
    std::cout << std::boolalpha;
    std::cout << isEqual(f, f2) << '\n';

    Friend2 f3 { 10 };
    std::cout << isEqual(f, f3) << '\n';

    return 0;
}

