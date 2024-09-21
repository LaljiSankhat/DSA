"""

386. Lexicographical Numbers
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104

"""


def lexicalOrder(n):
    res = []

    def dfs(cur):
        if cur > n:
            return
        res.append(cur)

        cur *= 10
        for i in range(10):
            dfs(cur + i)

    for i in range(1, 10):
        dfs(i)


    return res


# optimal approch
def lexical(n):
    res = []
    cur = 1
    while len(res) < n:
        res.append(cur)

        if cur * 10 <= n:
            cur *= 10
        else:
            while cur == n or cur % 10 == 9:
                cur = cur // 10
            cur += 1

    return res

# there is also a third approch where we convert number to string then sort and then convert to integer
def lexicalOrder2(n):
    s = []
    for i in range(1, n + 1):
        s.append(str(i))

    s = sorted(s)
    for i in range(len(s)):
        s[i] = int(s[i])

    return s

print(lexicalOrder(10))

