#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name {};

public:
    Person(std::string_view name)
        : m_name { name }
    {
    }

    void print() const
    {
        std::cout << m_name << '\n';
    }
};

Person test()
{
    return { "Test" };
}

void print(const Person& p)
{
    p.print();
}

int main()
{
    Person p { "Tony" };
    print(p);

    print( Person { "Ping" });
    print( { "Matthew" } );
    print(test());

    return 0;
}

