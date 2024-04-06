#include "timer.hpp"
#include <iostream>
#include <string>

bool isPalindrome(int x)
{
    std::string_view x_str { std::to_string(x) };
    int x_str_len { static_cast<int>(x_str.length()) };

    for (int start { 0 }; start < x_str_len / 2; ++start)
    {
        if (x_str[start] != x_str[x_str_len - 1 - start])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    const int t1 { 121 };
    const int t2 { -121 };
    const int t3 { 10 };

    std::cout << t1 << isPalindrome(t1) << '\n';
    std::cout << t2 << isPalindrome(t2) << '\n';
    std::cout << t3 << isPalindrome(t3) << '\n';

    return 0;
}
