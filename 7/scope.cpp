#include <iostream>

int main()
{
    int y { 5 };

    {
        int x {};
        std::cin >> x;

        if (x == 4)
        {
            y = 4;
        }
    }

    std::cout << y << '\n';

    return 0;
}
