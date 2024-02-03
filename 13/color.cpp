#include <iostream>

enum Color
{
    red,
    green,
    blue,
};

int main()
{
    Color apple { red };
    Color pear { green };

    std::cout << apple << pear << '\n';

    return 0;
}
