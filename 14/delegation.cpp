#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    int m_x {};
    std::string m_name {};

public:
    Person(std::string_view name)
        : Person { name, 10 }
    {
    }

    Person(std::string_view name, int x)
        : m_x { x }, m_name { name }
    {
    }

    void print()
    {
        std::cout << m_x << m_name << '\n';
    }
};

int main()
{
    Person p { "Tony" };
    p.print();

    Person m { "Matthew", 18 };
    m.print();

    return 0;
}

