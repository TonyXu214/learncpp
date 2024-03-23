#include <iostream>

struct Foo
{
private:
    int m_x {};

public:
    Foo(int x) : m_x { x }
    {
    }

    friend bool operator>(const Foo& f1, const Foo& f2)
    {
        return (f1.m_x > f2.m_x);
    }

    friend std::ostream& operator<<(std::ostream& s, const Foo& f)
    {
        s << f.m_x;
        return s;
    }
};

template <typename T>
const T& max(const T& x, const T& y)
{
    return (x > y) ? x : y;
}

int main()
{
    Foo f { 5 };
    Foo g { 10 };
    std::cout << f << g << '\n';

    std::cout << max(f, g) << '\n';

    return 0;
}
