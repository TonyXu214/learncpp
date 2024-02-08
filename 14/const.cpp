#include <iostream>

struct Foo
{
    int m {};

    void print() const
    {
        std::cout << "bar" << m << '\n';
        // m = 14; // compile error
    }
};

int main()
{
    const Foo f {};
    f.print();

    return 0;
}

