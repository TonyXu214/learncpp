#include <functional>
#include <iostream>
#include <string_view>
#include <vector>

class Base
{
    private:
        int m_x {};

    public:
        Base(int x) : m_x { x }
        {
        }

        virtual std::string_view getName() const
        {
            return "I am Base";
        }

        virtual int getInt() const
        {
            return m_x;
        }
};

class Derived : public Base
{
    private:
        int m_y {};

    public:
        Derived(int x = 0, int y = 0)
            : Base { x }
            , m_y { y }
        {
        }

        virtual std::string_view getName() const
        {
            return "I am Derived";
        }

        virtual int getInt() const
        {
            return m_y;
        }
};

int main()
{
    Derived d { 5, 10 };
    Base b { d };

    std::cout << d.getInt() << '\n';
    std::cout << b.getInt() << '\n';

    std::vector<std::reference_wrapper<Base>> v {};
    v.push_back(d);
    v.push_back(b);

    for (const auto& ele : v)
    {
        std::cout << ele.get().getName() << '\n';
    }

    return 0;
}

