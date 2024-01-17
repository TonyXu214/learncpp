#include <iostream>
#include <random>
#include <chrono>

int main()
{
    // std::mt19937 mt { static_cast<std::mt19937::result_type>(
    //         std::chrono::steady_clock::now().time_since_epoch().count()
    //         ) };

    std::random_device rd{};
    std::seed_seq ss { rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    std::mt19937 mt { ss };

    std::uniform_int_distribution die6 { 1, 6 };

    for (int count { 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t';

        if (count % 5 == 0)
            std::cout << '\n';
    }

    return 0;
}

