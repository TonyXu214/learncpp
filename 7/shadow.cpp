#include <iostream>

int g_x { 11 };

int main()
{
    std::cout << g_x << '\n';

    int g_x { 12 };

    std::cout << g_x << '\n';
    std::cout << ::g_x << '\n';

    int apples { 5 };

    {
        std::cout << apples << '\n';

        int apples { 10 };

        std::cout << apples << '\n';

        apples = 20;

        std::cout << apples << '\n';
    }

    std::cout << apples << '\n';

    return 0;
}
