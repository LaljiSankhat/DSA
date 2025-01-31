


# this grredy appproch fais for some cases like "wwwzfvedwfvhsww"
def splitString(s):
    n = len(s)
    i = 0
    l = []
    while i < n:
        j = i + 1
        while j <= n and s[i:j] in l:
            j = j + 1
        if(j <= n):
            l.append(s[i:j])
        i = j

    return len(l)

# backtrack approch 

def splitString2(str):

    def helper(s, unique_set):
        if not s:
            return 0
        
        count = 0
        for i in range(1, len(s) + 1):
            substr = s[0:i]
            if substr not in unique_set:
                unique_set.add(substr)
                count = max(count, 1 + helper(s[i:], unique_set))
                unique_set.remove(substr)
        return count
    return helper(str, set())

print(splitString("oprgktkvteecx"))
print(splitString2("oprgktkvteecx"))

