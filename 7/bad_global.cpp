#include <iostream>

int init_x();
int init_y();

int g_x { init_x() };
int g_y { init_y() };
int getTest();


int main()
{
    std::cout << g_x << ' ' << g_y << '\n';

    std::cout << getTest() << '\n';
    return 0;
}

int init_x()
{
    return g_y;
}

int init_y()
{
    return 5;
}

