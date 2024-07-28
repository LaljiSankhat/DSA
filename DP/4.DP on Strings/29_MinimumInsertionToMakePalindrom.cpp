#include <bits/stdc++.h>
using namespace std;

/*
   LeetCode : 1312. Minimum Insertion Steps to Make a String Palindrome

Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

Constraints:
1 <= s.length <= 500
s consists of lowercase English letters.
*/

/* To solve this we have to observe that
  minimum insertion = s.length - longestPalindromSubsequences(s);
*/

int longestCommenSubsequenceSpace(int n, int m, string &s1, string &s2)
{
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    // base
    for (int i = 0; i <= n; i++)
        prev[0] = 0;

    // Loops
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                cur[j] = 1 + prev[j - 1];

            // if not Matches so we two cases 1. reduce string1 2. reduce
            // string 2
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }

    return prev[m];
}

int longestPalindromSubsequences(string &s)
{
    int n = s.size();

    string t = s;
    reverse(t.begin(), t.end());

    return longestCommenSubsequenceSpace(n, n, s, t);
}

int minInsertionToMakePalindrome(string &s){
    return (s.size() - longestPalindromSubsequences(s));
}

int main()
{
    string s = "lalji";
    cout << minInsertionToMakePalindrome(s) << endl;
    return 0;
}