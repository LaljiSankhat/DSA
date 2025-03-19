

# leetcode 3191. Minimum Operations to Make Binary Array Elements Equal to One I


def minOperation(nums):
    res = 0

    def flip(nums, ind):
        nums[ind] = 0 if nums[ind] else 1

    for i in range(len(nums) - 2):
        if nums[i] == 0:
            # flip this window of 3 
            flip(nums, i)
            flip(nums, i + 1)
            flip(nums, i + 2)
            res += 1

    if not nums[-1] or not nums[-2]:
        return -1
    return res


nums = [0,1,1,1,0,0]
print(minOperation(nums))

