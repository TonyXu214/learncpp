#include <iostream>
#include <string>

struct Example
{
    int x; // no initialization value (bad)
    int y {}; // value initialized by default
    int z { 2 }; // explicit default value
};

struct Employee
{
    // members are functions, variables, or types that belong to a struct or
    // class
    int wages {}; // member variable
    std::string name {}; // member variable
    int id; // not initialized by default, no initializer here
};

struct Car
{
    std::string model {};
    int year {};
};

int main()
{
    Employee joe {}; // empty braces ensure value-initialization
    Employee uninit_joe; // no initializer here
    std::cout << uninit_joe.id << '\n'; // undefined behavior

    Car my_car = { "Toyota", 2006 }; // copy-list initialization using braced list
    Car matts_car { "Toyota", 2013 }; // list initialization using braced list
    // Car moms_car ( "Toyota", 2000 ); // direct initialization using parenthesized list
    Car test_car { .model { "Tesla" }, .year { 2000 } }; // designated initializers
    test_car = { test_car.model, 2020 }; // assign using initializer list
    Car copy_car { test_car };

    Something example; // x uninitialized, y is 0, z is 2
    Something example2 { 5, 6, 7 }; // no default values used, 5, 6, 7 respectively
    Something example3 {}; // x is value initialized, y is value initialized by default, z is defaulted to 2

    return 0;
}
