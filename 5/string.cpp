#include <iostream>
#include <string>

int main()
{
    // std::string num {};
    // std::string str {};
    // // std::string color {};
    //
    // std::cout << "Please pick a number 1 or 2: ";
    //
    // std::cin >> num;
    //
    // std::cout << "What's your full name?: ";
    //
    // std::getline(std::cin >> std::ws, str); // breaks without >> std::ws
    //
    // int length { static_cast<int>(str.length()) };
    // // int slength { std::ssize(str) };
    // std::cout << num << ' ' << str << length << std::ssize(str) << "fooooo\n";

    using namespace std::string_literals;

    constexpr std::string name{ "Anthony"s }; // compile error

    std::cout << "My name is: " << name;
    // std::cout << "Enter your full name: ";

    // std::getline(std::cin >> std::ws, str);

    // std::cin >> str;
    //
    // std::cout << str << '\n';
    //
    // std::cout << "What's your favorite color?: ";
    //
    // std::getline(std::cin >> std::ws, color);
    //
    // std::cout << str << ' ' << color << '\n';

    return 0;
}
