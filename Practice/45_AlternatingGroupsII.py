

# leetcode 3208. Alternating Groups II

# this will give TLE 
def numberOfAlternatingGroups(colors, k):
    groups = 0
    n = len(colors)


    def isValid(l, r):
        i = l + 1
        while i <= r:
            if colors[i % n] == colors[(i - 1) % n]: 
                return False
            i += 1
            
        return True
    
    l = 0
    r = k - 1

    while l < n:
        if isValid(l, r):
            groups += 1
        l += 1
        r += 1


    return groups


def numberOfAlternatingGroups2(colors, k):
    groups = 0
    n = len(colors)

    currentLength = 0

    l = r = 0

    while l < n:
        currentLength += 1
        if r != 0 and colors[r % n] == colors[(r - 1) % n]:
            l = r
            currentLength = 1
        elif currentLength == k:
            groups += 1
            l += 1
            currentLength -= 1
        r += 1

    return groups


l = [0,1,0,0,1,0,1]
k = 6
print(numberOfAlternatingGroups(l, k))
print(numberOfAlternatingGroups2(l, k))