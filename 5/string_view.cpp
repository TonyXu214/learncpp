#include <iostream>
#include <string>
#include <string_view>

std::string_view firstAlpha(std::string_view one, std::string_view two)
{
    return one < two ? one: two;
}

std::string_view getBoolNameC(bool b)
{
    if (b)
        return "true";

    return "false";
}

std::string_view getBoolName(bool b)
{
    std::string t { "true" };  // local variable
    std::string f { "false" }; // local variable

    if (b)
        return t;  // return a std::string_view viewing t

    return f; // return a std::string_view viewing f
} // t and f are destroyed at the end of the function

std::string retS()
{
    std::string s {'a'};
    return s;
}

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

    std::string_view badsv {};

    {
        std::string s {"hi there!"};
        badsv = s;
    }

    std::cout << badsv << '\n'; // undefined behavior

    std::string_view anotherbadsv {retS()};

    std::cout << anotherbadsv << '\n'; // undefined behavior

    std::string_view badSvFromSLiteral { "Sv"s }; // "Sv"s is temporary
    std::cout << badSvFromSLiteral << '\n';

    std::string modS { "will be modified " };
    std::string_view modSv { modS };

    std::cout << modSv << '\n';

    modS = "modified";

    std::cout << modSv << '\n'; // invalidated modSv

    modSv = modS;

    std::cout << modSv << '\n'; // revalidated

    // local variables in func destroyed
    std::string_view badLocals { getBoolName(true) };

    std::cout << badLocals << '\n';

    std::string_view goodLocals { getBoolNameC(true) };

    std::cout << goodLocals << '\n';

    std::string one { "z" };
    std::string two { "y" };

    std::cout << firstAlpha(one, two) << '\n';

    std::string_view remove { "Peach" };
    std::cout << remove << '\n';

    remove.remove_prefix(1);

    std::cout << remove << '\n';

    remove.remove_suffix(2);
    std::cout << remove << '\n';

    remove = "Peach";

    std::cout << remove << '\n';

    return 0;
}
