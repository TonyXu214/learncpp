#include <iostream>

struct Foo
{
    struct Bar
    {
        int x {};
    };

    int y {};
    Bar bar {};
};

int main()
{
    Foo f { 1, { 2 } }; // nested initialization list

    return 0;
}

