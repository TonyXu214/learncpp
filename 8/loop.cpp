#include <iostream>

int main()
{
    while (true)
    {
        std::cout << "loop again?" << '\n';

        bool loop {};
        std::cin >> loop;

        if (!loop)
        {
            return 0;
        }
    }

    return 0;
}
