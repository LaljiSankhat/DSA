

# leetcode 2401. Longest Nice Subarray



def longestNiceSubarray(nums):
    res = 0

    cur = 0 

    l = 0
    for r in range(len(nums)):
        while (cur & nums[r]) != 0:
            cur = cur ^ nums[l]
            l += 1
        res = max(res, r - l + 1)
        cur = cur | nums[r]

    return res



nums = [1,3,8,48,10]
print(longestNiceSubarray(nums))