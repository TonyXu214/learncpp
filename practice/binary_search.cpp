#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int start { 0 };
    int end { static_cast<int>(nums.size()) - 1 };

    while (start <= end)
    {
        const auto idx { (start + end) / 2 };
        std::cout << "start: " << start << " end: " << end << " idx: " << idx << " nums[idx]: " << nums[idx] << " target: " << target << '\n';

        if (nums[idx] == target)
            return idx;
        else if (nums[idx] < target)
            start = idx + 1;
        else
            end = idx - 1;
    }

    return start;
}

int main()
{
    std::vector<int> vec { 1, 3, 5, 6 };
    int one { 5 };
    int two { 2 };
    int three { 7 };
    int four { 0 };
    std::cout << searchInsert(vec, one) << '\n';
    std::cout << searchInsert(vec, two) << '\n';
    std::cout << searchInsert(vec, three) << '\n';
    std::cout << searchInsert(vec, four) << '\n';

    return 0;
}
