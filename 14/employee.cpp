#include <iostream>

class Employee // members are private by default
{
    std::string first_name {};
    char initial {};

public:
    void setName(std::string_view name)
    {
        first_name = name;
        initial = name.front();
    }

    void print() const
    {
        std::cout << first_name << initial << '\n';
    }

};

int main()
{
    Employee e;
    e.setName("tony");
    e.print();

    return 0;
}

