


"""

214. Shortest Palindrome
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.



"""

def shortestPalindrome(s) -> str:
    prefix = 0
    suffix = 0
    base = 29
    last_index = 0
    power = 1
    mod = 10**9 + 7

    for i, c in enumerate(s):
        char = (ord(c) - ord('a') + 1)  # extract value like for a is 1

        prefix = (prefix * base) % mod
        prefix = (prefix + char) % mod

        suffix = (suffix + char * power) % mod
        power = (power * base) % mod

        if prefix == suffix:
            last_index = i

    suffix = s[last_index + 1:]
    return suffix[::-1] + s


print(shortestPalindrome(s="aaba"))


