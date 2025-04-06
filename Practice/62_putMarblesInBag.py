# leetcode 2551. Put Marbles in Bags

def putMarbles(weights, k):
    if len(weights) == k or k == 1: 
        return 0
    splits = []

    for i in range(len(weights) - 1):
        splits.append(weights[i] + weights[i + 1])

    splits.sort()

    max_sum = sum(splits[-k + 1:])
    min_sum = sum(splits[:k - 1])

    return max_sum - min_sum



weights = [1,3,5,1]
k = 2

print(putMarbles(weights, k)) # Output: 4