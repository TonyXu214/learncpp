#include "pair.hpp"

template <typename T>
using Point_T = Pair<T>;

template <typename T>
void printPoint_T(Point_T<T> p)
{
    std::cout << p.first << p.second << '\n';
}

template <typename T>
void print(const Point_T<T>& c)
{
    std::cout << c.first << ' ' << c.second << '\n';
}

int main()
{
    using Point = Pair<int>;
    Point point { 2, 3 };
    printPair(point);

    Point_T<double> pointt { 3.4, 5.4 };
    point(pointt);

    Point_T deduced { 5.4, 6.9 };
    printPair(deduced);

    Pair<int> p { 1, 2 };
    printPair(p);

    return 0;
}
