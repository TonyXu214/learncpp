#!/usr/bin/env python3

def searchInsert(nums, target):
    start = 0
    end = len(nums) - 1

    while (start <= end):
        idx = (start + end) // 2

        if (target == nums[idx]):
            return idx
        elif (target > nums[idx]):
            start = idx + 1
        else:
            end = idx - 1

    return start

def main():
    print(searchInsert([1, 3, 5, 6], 5))
    print(searchInsert([1, 3, 5, 6], 2))
    print(searchInsert([1, 3, 5, 6], 7))
    print(searchInsert([1, 3, 5, 6], 0))

if __name__ == '__main__':
    main()
