#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>

void invoke(const std::function<void()>& fn)
{
    fn();
}

int main()
{
    int i { 0 };
    auto fn {
        [=]() mutable
        {
            std::cout << ++i << '\n';
        }
    };

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    invoke(std::ref(fn));
    invoke(std::ref(fn));
    invoke(std::ref(fn));

    std::array areas { 10, 12 };
    int width {};
    int height {};
    std::cin >> width >> height;
    auto found2 { std::find_if(areas.begin(), areas.end(),
            [=](int i)
            {
            return width * height == i;
            }) };
    auto found3 { std::find_if(areas.begin(), areas.end(),
            // Declare a new variable that's visible only to the lambda.
            // The type of userArea is automatically deduced to int.
            [area { width * height }](int i)
            {
            return area == i;
            }) };
    if (found2 != areas.end())
    {
        std::cout << *found2 << '\n';
    }
    if (found3 != areas.end())
    {
        std::cout << *found3 << '\n';
    }
    int ammo { 10 };
    int start { 0 };
    auto shoot {
        [start, &ammo]() mutable // mutable needed if pass by value, not if pass by reference
        {
            std::cout << "pew! ammo remaining: " << --ammo << '\n';
            std::cout << "start: " << ++start << '\n';
        }
    };
    shoot();
    shoot();
    std::cout << "ammo remaining: " << ammo << '\n'; // captured by reference
    constexpr std::array arr { "foo", "bar", "baz" };
    std::cout << "search for: ";
    std::string search {};
    std::cin >> search;
    std::cout << search << '\n';

    auto found { std::find_if(arr.begin(), arr.end(),
                              [search](std::string_view str)
                              {
                                  return str.find(search) != std::string_view::npos;
                              }) };
    if (found != arr.end())
    {
        std::cout << "found: " << *found << '\n';
    }

    return 0;
}

