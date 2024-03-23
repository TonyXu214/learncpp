#include <iostream>

class Foo
{
private:
    int m_arr[10] {};

public:
    Foo() = default;

    int& operator[](int x);
};

int& Foo::operator[](int x)
{
    return m_arr[x];
}

int main()
{
    Foo foo {};
    std::cout << foo[2] << '\n';
    foo[2] = 5;
    std::cout << foo[2] << '\n';

    return 0;
}
