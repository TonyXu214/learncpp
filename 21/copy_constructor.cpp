#include <iostream>

class Foo
{
private:
    int m_x {};

public:
    Foo(int x) : m_x { x }
    {
    }

    Foo& operator=(const Foo& f1)
    {
        if (this == &f1)
            return *this;

        m_x = f1.m_x;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& s, const Foo& f);
};

std::ostream& operator<<(std::ostream& s, const Foo& f)
{
    s << f.m_x;
    return s;
}

int main()
{
    Foo f { 5 };
    Foo g { 10 };

    std::cout << f << g << '\n';
    f = g;
    std::cout << f << g << '\n';

    return 0;
};
