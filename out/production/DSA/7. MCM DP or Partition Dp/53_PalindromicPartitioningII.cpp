#include <bits/stdc++.h>
using namespace std;


/*
    132. Palindrome Partitioning II
Given a string s, partition s such that every 
substring of the partition is a palindrome
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
 

Constraints:
1 <= s.length <= 2000
s consists of lowercase English letters only.
*/

/*
    Here we have to find minimum number of partition for that every substring will become palindrom.
    To solve this we have use "Front Partition" method in which we will start partition from first element 
    then we check if before partition substring is palindrome then we will find minimum answer of right partition
    and add in it.
*/

bool isPalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return 0;
        i++;
        j--;
    }

    return 1;
}


int minPartiton(int i, string &s){
    if(i == s.length()) return 0;

    int mini = INT_MAX;
    for(int j = i; j < s.length(); j++){
        int res = 1e9;
        if(isPalindrome(i, j, s)){
            res = 1 + minPartiton(j + 1, s);
        }
        mini = min(mini, res);
    }

    return mini;
}

// memoization
int minPartitonDp(int i, string &s, vector<int> &dp){
    if(i == s.length()) return 0;
    if(dp[i] != -1) return dp[i];

    int mini = INT_MAX;
    for(int j = i; j < s.length(); j++){
        int res = 1e9;
        if(isPalindrome(i, j, s)){
            res = 1 + minPartitonDp(j + 1, s, dp);
        }
        mini = min(mini, res);
    }

    return dp[i] = mini;
}

// Tabulation
int minPartitonTab(string &s){
    int n = s.size();
    vector<int> dp(n + 1, 0);


    for(int i = n - 1; i >= 0; i--){
        int mini = INT_MAX;
        for (int j = i; j < s.length(); j++)
        {
            int res = 1e9;
            if (isPalindrome(i, j, s))
            {
                res = 1 + dp[j + 1];
            }
            mini = min(mini, res);
        }

        dp[i] = mini;
    }

    return dp[0] - 1;    
}



int main(){
    string s = "aab";
    int n = s.length();
    vector<int> dp(n, -1);
    cout << minPartiton(0, s) - 1 << endl;
    // We substract one becuase at the end function will do partition we dont need that so we reomove that
    cout << minPartitonDp(0, s, dp) - 1 << endl;
    cout << minPartitonTab(s) << endl;
    return 0;
}