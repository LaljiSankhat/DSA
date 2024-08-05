#include <bits/stdc++.h>
using namespace std;


/*
    1048. Longest String Chain

You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in 
wordA without changing the order of the other characters to make it equal to wordB.
For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is 
a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Example 1:
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

Example 2:
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].

Example 3:
Input: words = ["abcd","dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.

*/

/* 
    it is extention of previos question but here we check for string so we make a checkPossible function for checking two 
    strings befor that we have to sort the string array based on length of strings
*/


bool checkPossible(string &s1, string &s2){
    int m = s1.size();
    int n = s2.size();
    if(abs(m - n) != 1) return 0;
    int first = 0;
    int second = 0;
    while(first < m){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return 1;
    return 0;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStringChain(int n, vector<string> &words){
    vector<int> dp(n, 1);

    sort(words.begin(), words.end(), comp);

    int maxi = 1;

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(checkPossible(words[i], words[prev]) && dp[prev] + 1 > dp[i]){
                dp[i] = dp[prev] + 1;

            }
        }
        if(maxi < dp[i]) maxi = dp[i];
    }
    return maxi;
}




int main(){
    vector<string> nums = {"a","b","ba","bca","bda","bdca"};
    int n = nums.size();
    // int lis = longestStringChain(n, nums);
    // for(auto a : lis) cout << a << " ";
    cout << longestStringChain(n, nums) << endl;
    return 0;
}