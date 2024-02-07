#include <iostream>

struct Person
{
    std::string name {};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

struct Date_struct
{
    int day{};
    int month{};

    void print()
    {
        std::cout << day << month << '\n';
    }
};

class Date
{
public:
    int m_day{};
    int m_month{};
};

void printDate(const Date& date)
{
    std::cout << date.m_day << date.m_month << '\n';
}

int main()
{
    Date date { 4, 10 };
    printDate(date);

    Date_struct date_struct { 5, 11 };
    date_struct.print();

    Person j { "Joe" };
    Person k { "Kate" };

    j.kisses(k);

    return 0;
}

