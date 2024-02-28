#include <iostream>

struct MyChars
{
    char a {};
    char b {};
    char c {};
};

class Foo
{
private:
    static MyChars generate() // A lambda can also be used for this.
    {
        MyChars chars {};
        chars.a = 'a';
        chars.b = 'b';
        chars.c = 'c';

        return chars;
    }

public:
    static inline MyChars s_mychars { generate() };
};

int main()
{
    std::cout << Foo::s_mychars.a << '\n';
    std::cout << Foo::s_mychars.b << '\n';
    std::cout << Foo::s_mychars.c << '\n';

    return 0;
}
