#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

template <typename T, std::size_t L>
void repeat1(std::array<T, L> arr, const std::function<void(int)>& fn)
{
    for (auto& ele : arr)
    {
        fn(ele);
    }
    std::cout << '\n';
}

template <typename T, std::size_t L, typename F>
void repeat2(std::array<T, L> arr, const F& fn)
{
    for (auto& ele : arr)
    {
        fn(ele);
    }
    std::cout << '\n';
}

void repeat3(const auto& arr, const auto& fn)
{
    for (auto& ele : arr)
    {
        fn(ele);
    }
    std::cout << '\n';
}

bool find(std::string_view str)
{
    return str.find("nut") != std::string_view::npos;
}


int main()
{
    auto print {
        [](const auto& foo)
        {
            static int count { 0 };
            std::cout << foo << ' ' << ++count << '\n';
        } };
    print("1");
    print("2");
    print(3);
    print(4);
    print("5");
    constexpr std::array months { "Jan", "Feb", "March", "May"};
    const auto adj { std::adjacent_find(months.begin(), months.end(),
                     [](const auto& x, const auto& y)
                     {
                         return x[0] == y[0];
                     }) };
    if (adj != months.end())
        std::cout << *adj << ' ' << *std::next(adj) << '\n';
    auto fn { [](int i)
              {
                  std::cout << i << ' ';
              } };
    std::array<int, 5> ar { 5, 4, 3, 2, 1 };
    repeat1(ar, fn);
    repeat2(ar, fn);
    repeat3(ar, fn);
    constexpr std::array<std::string_view, 3> arr { "foo", "bar", "pnut" };
    // auto found { std::find_if(arr.begin(), arr.end(), find) };
    auto found_lambda { std::find_if(arr.begin(), arr.end(),
                                     [](std::string_view str)
                                     {
                                         return str.find("nut") != std::string_view::npos;
                                     }) };

    if (found_lambda == arr.end())
    {
        std::cout << "no nut" << '\n';
    } else {
        std::cout << *found_lambda << '\n';
    }

    std::array<int, 4> int_arr { 1, 2, 3, 4 };
    auto isEven { [](int i)
                  {
                      return (i % 2) == 0;
                  } };

    auto test { std::all_of(int_arr.begin(), int_arr.end(), isEven) };
    std::cout << std::boolalpha;
    std::cout << test << '\n';

    double (*addNumbers)(double x, double y) {
        [](double x, double y)
        {
            return x + y;
        }
    };

    std::function addNumbersStd {
        [](double x, double y)
        {
            return x + y;
        }
    };

    auto addNumbersAuto {
        [](double x, double y)
        {
            return x + y;
        }
    };

    std::cout << addNumbers(5.0, 6.0) << '\n';
    std::cout << addNumbersStd(6.0, 6.0) << '\n';
    std::cout << addNumbersAuto(7.0, 6.0) << '\n';

    return 0;
}
