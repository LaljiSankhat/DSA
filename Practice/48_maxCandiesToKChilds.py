

# leetcode 2226. Maximum Candies Allocated to K Children

def maximumCandies(candies, k):
    s = sum(candies)
    if s  < k: return 0

    res = 0
    left = 1
    right = (s // k)

    # def isPossible(mid):
    #     given = 0
    #     for num in candies:
    #         given += (num // mid)
    #     if given < k: return 0
    #     return True


    while left <= right:
        mid = (right + left) // 2
        count = 0 


        for c in candies:
            if c >= mid:
                count += c // mid
            if count >= k:
                break
        
        if count >= k: 
            res = mid
            left = mid + 1
        else:
            right = mid - 1

    return res

candies = [4,7,5]
k = 4
print(sum(candies))
print(maximumCandies(candies, k))

