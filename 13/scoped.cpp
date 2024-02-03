#include <iostream>

int main()
{
    enum class Color
    {
        red,
        blue,
    };

    enum class Mood
    {
        red,
        blue,
    };

    using enum Color;

    Color c { Color::red };
    Color c1 { blue }; // able to do so because of using enum Color
    Mood m { Mood::blue };

    std::cout << static_cast<int>(c) << static_cast<int>(m) << static_cast<int>(c1) << '\n';

    // if (c == m) std::cout << "true" << '\n'; // compile error

    return 0;
}

