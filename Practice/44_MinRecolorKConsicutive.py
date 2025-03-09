

def minimumRecolor(str, k):
    l = r = 0
    n = len(str)
    operations = 0 
    colorLength = 0
    minOperations = n

    while r < n:
        if str[r] == 'W':
            operations = operations + 1
        colorLength += 1
        while l <= r and colorLength >= k:
            minOperations = min(minOperations, operations)
            if str[l] == 'W':
                operations -= 1
            colorLength -= 1
            l += 1
        r += 1
    return minOperations

print(minimumRecolor("WBWBBBW", 2))