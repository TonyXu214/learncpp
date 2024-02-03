#include <iostream>

namespace Flags
{
    enum Moods
    {
        isHappy,
        isLaughing,
        isCrying,
    };
}

int main()
{
    std::bitset<8> me{};
    me.set(Flags::isHappy);

    std::cout << std::boolalpha;

    std::cout << "Is happy?: " << me.test(Flags::isHappy) << '\n';
    std::cout << "Is laughing?: " << me.test(Flags::isLaughing) << '\n';

    return 0;
}

