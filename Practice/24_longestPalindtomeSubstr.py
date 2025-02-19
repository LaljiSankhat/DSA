# leetcode 5 : longest palindromic substring


def longestPalindrome(s: str) -> str:
    def expand(s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1:right]
        
    res = ""
    for i in range(len(s)):
        odd = expand(s, i, i)        
        even = expand(s, i, i + 1)
        if len(odd) > len(res):
            res = odd
        if len(even) > len(res):    
            res = even
    return res



print(longestPalindrome("babad")) # bab