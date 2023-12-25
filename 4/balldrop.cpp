#include <iostream>

#define GRAVITY 9.8

double getTowerHeight()
{
    double x {};

    std::cout << "What is the height of the tower? ";
    std::cin >> x;

    return x;
}

void fallenHeight(double towerHeight)
{
    double fallen_0 { towerHeight - GRAVITY * 0.0 * 0.0 / 2.0 };
    double fallen_1 { towerHeight - GRAVITY * 1.0 * 1.0 / 2.0 };
    double fallen_2 { towerHeight - GRAVITY * 2.0 * 2.0 / 2.0 };
    double fallen_3 { towerHeight - GRAVITY * 3.0 * 3.0 / 2.0 };
    double fallen_4 { towerHeight - GRAVITY * 4.0 * 4.0 / 2.0 };
    double fallen_5 { towerHeight - GRAVITY * 5.0 * 5.0 / 2.0 };

    std::cout << fallen_0 << '\n';
    std::cout << fallen_1 << '\n';
    std::cout << fallen_2 << '\n';
    std::cout << fallen_3 << '\n';
    std::cout << fallen_4 << '\n';
    std::cout << fallen_5 << '\n';
}

int main()
{
    double towerHeight { getTowerHeight() };

    fallenHeight(towerHeight);

    return 0;
}
