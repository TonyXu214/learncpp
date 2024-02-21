#include <iostream>

class Person
{
public:
    const std::string& get_name()
    {
        return m_name;
    }

    void set_name(std::string_view name)
    {
        m_name = name;
    }

    void kisses(const Person& p) const
    {
        std::cout << m_name << " kisses " << p.m_name << '\n';
    }

private:
    std::string m_name {};
};

Person createPerson(std::string_view name)
{
    Person p {};
    p.set_name(name);

    return p;
}

struct Public
{
    int x {};
};

class Private
{
public:
    void print() const
    {
        std::cout << m_x << '\n';
    }

private:
    int m_x { 5 };
};

int main()
{
    std::cout << createPerson("Tony").get_name() << '\n';

    // const std::string& name { createPerson("Tony").get_name() }; // dangling
    // std::string name { createPerson("Tony").get_name() }; // okay, copies

    Public pu { 1 };
    std::cout << pu.x << '\n';

    Private pri{};
    pri.print();

    Person joe {};
    joe.set_name("Joe");

    Person kate {};
    kate.set_name("Kate");

    joe.kisses(kate);

    std::cout << joe.get_name() << '\n';

    return 0;
}
