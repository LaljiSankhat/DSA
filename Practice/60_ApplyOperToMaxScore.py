# 2818. Apply Operations to Maximize Score

from math import sqrt
from heapq import heapify, heappop


def maximumScore(nums, k):
    N = len(nums)
    MOD = 10**9 + 7
    res = 1

    # calculating the prime scores
    prime_scores = [] 
    for n in nums:
        score = 0   
        for f in range(2, int(sqrt(n)) + 1):
            if n % f == 0:
                score += 1
                while n % f == 0:
                    n = n // f

        if n >= 2:
            score += 1
        prime_scores.append(score)


    # calculating the monotonic stacks
    left_bound = [-1] * N    
    right_bound = [N] * N
    stack = []

    for i,s in enumerate(prime_scores):
        while stack and prime_scores[stack[-1]] < s:
            index = stack.pop()
            right_bound[index] = i
        if stack:
            left_bound[i] = stack[-1]
        stack.append(i)

    # calculating the max score
    min_heap = [(-n, i) for i, n in enumerate(nums)]
    heapify(min_heap)

    while k > 0:
        n, index = heappop(min_heap)
        n = -n
        score = prime_scores[index]

        left_count = index - left_bound[index]
        right_count = right_bound[index] - index

        count = left_count * right_count
        operations = min(k, count)
        res = (res * pow(n, operations, MOD)) % MOD

        k -= operations
    return res

nums = [8,3,9,3,8]
k = 2

print(maximumScore(nums, k)) # Expected output: 81  