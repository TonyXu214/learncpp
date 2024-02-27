#include <iostream>

class Fruit
{
public:
    using IDType = int;
    enum Type
    {
        apple,
        banna,
        grape
    };

private:
    Type m_type {};
    IDType m_typedef {};

public:
    class Printer
    {
    public:
        void print(const Fruit& f)
        {
            std::cout << f.m_type << f.m_typedef << '\n';
        }
    };

    Fruit(Type type, IDType foo=0)
        : m_type { type }
        , m_typedef {foo}
    {
    }

    Type getType()
    {
        return m_type;
    }

    bool isGrape()
    {
        return m_type == grape;
    }

    IDType getFoo()
    {
        return m_typedef;
    }

    void print()
    {
        std::cout << m_type << m_typedef << '\n';
    }
     ~Fruit()
     {
         std::cout << "Destroying fruit" << '\n';
     }
};

int main()
{
    Fruit f { Fruit::apple };
    Fruit g { Fruit::apple, 5 };
    Fruit::Printer print {};
    print.print(g);
    Fruit::IDType test { g.getFoo() };
    std::cout << test << '\n';

    f.print();
    g.print();
    std::cout << f.isGrape() << '\n';
    std::cout << (f.getType() == Fruit::apple) << '\n';

    return 0;
}
