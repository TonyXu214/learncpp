#include <iostream>
#include <vector>

int main()
{
    std::vector<int> int_vec { 1, 2, 3 }; // list initialization with no elements
    std::vector char_vec { 'a', 'b', 'c' }; // CTAD used
    std::vector<int> len_10_vec ( 10 ); // must use direct initialization

    std::cout << int_vec[0] << int_vec[1] << '\n';
    std::cout << &(int_vec[0]) << '\n' << &(int_vec[1]) << '\n' << &(int_vec[2]) << '\n';
    std::cout << char_vec[0] << char_vec[1] << '\n';


    // std::vector<int> v4 = { 10 }; // initializer list, list constructor
    // std::vector<int> v5 ({ 10 }); // initializer list, list constructor

    std::vector<int> arr(3); // create a vector of length 3

	std::cout << "Enter 3 integers: ";
	std::cin >> arr[0] >> arr[1] >> arr[2];

    std::cout << arr[0] << '\n';
	std::cout << "The sum is: " << arr[0] + arr[1] + arr[2] << '\n';
	std::cout << "The product is: " << arr[0] * arr[1] * arr[2] << '\n';

    return 0;
}

