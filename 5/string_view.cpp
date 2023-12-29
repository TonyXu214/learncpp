#include <iostream>
#include <string>
#include <string_view>

void sFromSv(std::string s)
{
    std::cout << "In sFromSv func " << s << '\n';
}

void svFromCstr(std::string_view sv)
{
    std::cout << "In svFromCstr func " << sv << '\n';
}

void svFromS(std::string_view sv)
{
    std::cout << "In svFromS func " << sv << '\n';
}

void svFunc(std::string_view sv)
{
    std::cout << "In sv func " << sv << '\n';
}

int main()
{
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    std::string_view sv { "Hello! "};
    std::string s { "This is a string" };
    std::string_view svs { s };
    std::string_view svsv { sv };
    std::string_view svLiteral { "literally an sv"sv };

    std::cout << sv << '\n';
    std::cout << s << '\n';
    std::cout << svs << '\n';
    std::cout << svsv << '\n';

    svs = "tony";

    std::cout << s << '\n';
    std::cout << svs << '\n';
    std::cout << svLiteral << '\n';

    svFunc(sv);
    svFromS(static_cast<std::string>("hi"));
    svFromCstr("hi");

    sFromSv(static_cast<std::string>(sv));

    return 0;
}
