#!/usr/bin/env python3

def removeDuplicates(nums):
    curIdx = 0
    runIdx = 1

    while (runIdx < len(nums)):
        if (nums[curIdx] != nums[runIdx]):
            curIdx += 1
            nums[curIdx] = nums[runIdx]
        runIdx += 1

    print(nums)
    return curIdx + 1

def main():
    one = [1,1,2]
    two = [0,0,1,1,1,2,2,3,3,4]

    removeDuplicates(one)
    print(one)
    removeDuplicates(two)
    print(two)

if __name__ == "__main__":
    main()
