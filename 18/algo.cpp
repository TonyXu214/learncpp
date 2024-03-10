#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string_view>
#include <chrono> // for std::chrono functions

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::steady_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<Clock> m_beg { Clock::now() };

public:
	void reset()
	{
		m_beg = Clock::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
	}
};

bool greater(int a, int b)
{
    return a < b;
}

bool findNut(std::string_view str)
{
    return (str.find("nut") != std::string_view::npos);
}

void doubleNum(int& x)
{
    x *= 2;
}

int main()
{
    Timer t;
    std::array arr_int { 3, 4, 1, 5, 0 };
    for (auto i : arr_int)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::cout << "Elapsed: " << t.elapsed() << '\n';
    // std::for_each(arr_int.begin(), arr_int.end(), doubleNum);
    // for (auto i : arr_int)
    // {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';
    // std::sort(arr_int.begin(), arr_int.end(), std::greater{});
    // for (auto i : arr_int)
    // {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';
    //
    // std::array<std::string_view, 3> str_arr { "almond", "walnut", "pecan" };
    // auto iter { std::find_if(str_arr.begin(), str_arr.end(), findNut) };
    // if (iter == str_arr.end())
    // {
    //     std::cout << "nut not found" << '\n';
    // } else
    // {
    //     std::cout << *iter << '\n';
    // }
    //
    // std::array arr { 50, 11, 22, 99, 100, 3 };
    //
    // std::cout << "Please enter search and replace terms: ";
    // int search {};
    // int replace {};
    // std::cin >> search >> replace;
    //
    // auto found { std::find(arr.begin(), arr.end(), search) };
    //
    // std::cout << "Before" << '\n';
    // for (const auto i : arr)
    // {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';
    //
    // if (found == arr.end())
    // {
    //     std::cout << "Term could not be found" << '\n';
    // } else
    // {
    //     *found = replace;
    // }
    //
    // std::cout << "After" << '\n';
    // for (const auto i : arr)
    // {
    //     std::cout << i << ' ';
    // }
    // std::cout << '\n';

    return 0;
}

