#include <iostream>

using namespace std::literals;

class Employee
{
private:
    std::string m_name {};

public:
    Employee(std::string_view name)
        : m_name { name }
    {
    }

    const std::string& getName() const
    {
        return m_name;
    }
};

class Foo
{
private:
    int m_x {};

public:
    Foo(int x)
        : m_x { x }
    {
    }

    int get_x() const
    {
        return m_x;
    }
};

void printX(Foo f)
{
    std::cout << f.get_x() << '\n';
}

void printEmployee(Employee e)
{
    std::cout << e.getName() << '\n';
}

class Dollars
{
private:
    int m_dollars {};

public:
    explicit Dollars(int dollars)
        : m_dollars { dollars }
    {
    }

    int getDollars() const
    {
        return m_dollars;
    }
};

void print(Dollars d)
{
    std::cout << d.getDollars() << '\n';
}

int main()
{
    printX(5);

    printEmployee("Joe"sv);

    print(5);

    return 0;
}

