# leetcode 2780. Minimum Index of a Valid Split

def minimumIndex(nums):
    def findDominant(l, r):
        freq = {}
        maxNumFreq = -1
        maxFreq = -1
        
        for i in range(l, r + 1):
            if nums[i] not in freq:
                freq[nums[i]] = 1
            else:
                freq[nums[i]] += 1
            if freq[nums[i]] > maxFreq:
                maxFreq = freq[nums[i]]
                maxNumFreq = nums[i]
        return maxNumFreq
            

    for i in range(len(nums) - 1):
        leftDominant = findDominant(0, i)
        rightDominant = findDominant(i + 1, len(nums) - 1)
        if leftDominant == rightDominant:
            return i

    return -1

nums = [2,1,3,1,1,1,7,1,2,1]
print(minimumIndex(nums))