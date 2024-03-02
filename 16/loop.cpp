#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores { 1, 2, 3, 4 };
    int sum {};

    for(std::size_t idx { 0 }; idx < scores.size(); ++idx)
    {
        sum += scores[idx];
    }

    std::cout << sum / static_cast<double>(scores.size()) << '\n';

    return 0;
}
