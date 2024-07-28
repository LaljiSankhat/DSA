#include <bits/stdc++.h>
using namespace std;


/* 
   LeetCode : 583. Delete Operation for Two Strings

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4 

Constraints:
1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
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

int minOperations(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    int a = longestCommenSubsequenceSpace(n, m, word1, word2);

    return (n + m - (2 * a));
}

int main(){
    string a = "abcd";
    string b = "anc";
    cout << minOperations(a, b) << endl;
    return 0;
}