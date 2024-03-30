#include <iostream>

template <typename T>
void print(const T& t)
{
    std::cout << t << '\n';
}

// non-template function
// void print(double t)
// {
//     std::cout << std::scientific << t << '\n';
// }

template <>
void print<double>(const double& d)
{
    std::cout << std::scientific << d << '\n';
}

int main()
{
    print(5);
    print(6.7);

    return 0;
}

