# leetcode 2560. House Robber IV

# pattern
# 1. Brute force
# 2. optimize
# 3. BS Range 

def minCapability(nums, k):
    l, r = min(nums), max(nums)
    res = 0

    def is_valid(capability):
        i = 0
        count = 0

        while i < len(nums):
            if nums[i] <= capability:
                i += 2
                count += 1
            else: 
                i += 1
            if count == k:
                break
        return count == k

    while l <= r:
        mid = (l + r) // 2

        if is_valid(mid):
            res = mid
            r = mid - 1
        else:
            l = mid + 1

    return res


nums = [2,3,5,9]
k = 2
print(minCapability(nums, k))
