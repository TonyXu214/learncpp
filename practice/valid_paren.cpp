#include <iostream>
#include <string>
#include <vector>

constexpr bool isValid(std::string_view s)
{
    std::vector<char> vec {};

    std::cout << s << '\n';
    for (const auto c : s)
    {
        if (c == '(' || c =='{' || c == '[')
        {
            vec.emplace_back(c);
        } else
        {
            if (vec.size() == 0) return false;

            if ((c == ')' && vec.back() != '(')
                    || (c == '}' && vec.back() != '{')
                    || (c == ']' && vec.back() != '['))
                return false;

            vec.pop_back();
        }
    }

    return true;
}

int main()
{
    constexpr std::string_view s1 { "()" };
    constexpr std::string_view s2 { "()[]{}" };
    constexpr std::string_view s3 { "(]" };
    std::cout << std::boolalpha;
    std::cout << isValid(s1) << '\n';
    std::cout << isValid(s2) << '\n';
    std::cout << isValid(s3) << '\n';

    return 0;
}
