
# leetcode 3306. Count of Substrings Containing Every Vowel and K Consonants II
from collections import defaultdict

def countSubstrings2(word, k):
    def atleast(k):
        vowel = defaultdict(int)
        non_vowel = 0
        res = 0
        l = 0

        for r in range(len(word)):
            if word[r] in 'aeiou':
                vowel[word[r]] += 1
            else:
                non_vowel += 1
            while len(vowel) == 5 and non_vowel >= k:
                res += len(word) - r
                if word[l] in 'aeiou':
                    vowel[word[l]] -= 1
                else: 
                    non_vowel -= 1
                if vowel[word[l]] == 0:
                    vowel.pop(word[l])
                l += 1


        return res
    
    return atleast(k) - atleast(k + 1)


# def countSubstrings(word, k):
#     vowels = defaultdict(int)
#     consonants = 0
#     n = len(word)
#     l = r = res = 0

#     while r < n:
#         if word[r] in 'aeiou':
#             vowels[word[r]] += 1
#         else:
#             consonants += 1
#         if len(vowels) == 5 and consonants == k:
#             res += 1
#         while l <= r and consonants > k:
#             if word[l] in 'aeiou':
#                 vowels[word[l]] -= 1
#                 if vowels[word[l]] == 0:
#                     del vowels[word[l]]
#             else:
#                 consonants -= 1
#             l += 1
#             # if len(vowels) == 5 and consonants == k:
#             #     res += 1
#         r += 1


#     while (r - l) >= k + 5:
        
#         if word[l] in 'aeiou':
#             vowels[word[l]] -= 1
#             if vowels[word[l]] == 0:
#                 del vowels[word[l]]
#         else:
#             consonants -= 1
#         l += 1
#         if len(vowels) == 5 and consonants == k:
#             res += 1
#     return res
                
                

# Test case
print(countSubstrings2("aoaiuefi", 1))  # Expected output: Correct count of valid substrings
