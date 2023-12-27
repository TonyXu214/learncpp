#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your age: ";
    int age {};
    std::cin >> age;

    std::cout << "What's your full name?: ";
    std::string name {};
    std::getline(std::cin >> std::ws, name);

    std::cout << age + std::ssize(name) << '\n';

    return 0;
}
