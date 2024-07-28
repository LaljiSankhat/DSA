#include <bits/stdc++.h>
using namespace std;

/*
   LeetCode : 516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some 
or no elements without changing the order of the remaining elements. 

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 
Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters.
*/

/* Here if we reverse the string and find the longest common subsequences between them then we will get our 
   required answer */
/* So just need to reverse the string and question is now become as question 25 */

int longestCommenSubsequenceSpace(int n, int m, string &s1, string &s2){
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    //base
    for(int i = 0; i <= n; i++) prev[0] = 0;

    //Loops
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (s1[i - 1] == s2[j - 1])
                cur[j] = 1 + prev[j - 1];

            // if not Matches so we two cases 1. reduce string1 2. reduce string2
            else cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }

    return prev[m];
}

int longestPalindromSubsequences(string &s){
    int n = s.size();

    string t = s;
    reverse(t.begin(), t.end());

    return longestCommenSubsequenceSpace(n, n, s, t);
}

int main(){
    string s = "bbbab";
    cout << longestPalindromSubsequences(s) << endl;
    return 0;
}