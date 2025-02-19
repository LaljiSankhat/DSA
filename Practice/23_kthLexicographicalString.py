# leetcode 1415 the k-th lexicographical string of all happy strings of length n


# this will give wrong ans because it does not check two consecutive characters are not same
def f(n: int, k: int, c: int) -> str:
    if n == 1:
        return "abc"[k - 1]
    # c = c // 2
    if k <= c:
        return 'a' + f(n - 1, k + 1, c // 2)
    elif (k <= 2 * c):
        return 'b' + f(n - 1, k - c, c // 2)
    else:
        return 'c' + f(n - 1, k - 2 * c, c // 2)


def getHappyString(n: int, k: int) -> str:
    c = 2 ** (n - 1)
    if k > 3 * c: 
        return ""
    print(f(n, k, c))

def generate_strings(n, cur, res):
    if len(cur) == n: 
        res.append(cur)
        return
    
    for ch in "abc":
        if not cur or cur[-1] != ch:
            generate_strings(n, cur + ch, res)

def getStrings(n, k):
    res = []
    generate_strings(n, "", res)
    res.sort()
    print(res[k - 1])

getHappyString(1, 4) # cab