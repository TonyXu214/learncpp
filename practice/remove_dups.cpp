#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums)
{
    int curIdx { 0 };
    int runnerIdx { 1 };

    while (runnerIdx < nums.size())
    {
        if (nums[curIdx] != nums[runnerIdx])
        {
            curIdx += 1;
            nums[curIdx] = nums[runnerIdx];
        }
        runnerIdx += 1;
    }

    return curIdx + 1;
}

int main()
{
    std::vector<int> one { 1, 1, 2 };
    std::vector<int> two { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

    std::cout << removeDuplicates(one) << '\n';
    for (auto i : one)
        std::cout << i << ' ';
    std::cout << '\n';
    std::cout << removeDuplicates(two) << '\n';
    for (auto i : two)
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
