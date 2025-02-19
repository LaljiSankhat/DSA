#include <bits/stdc++.h>
using namespace std;


// leetcode : 2345. Sum of Beauty of All Substrings
/*
    The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
    For example, the beauty of "abaacc" is 3 - 1 = 2.
    Given a string s, return the sum of beauty of all of its substrings.

    Example 1:

    Input: s = "aabcb"
    Output: 5
    Explanation: The substrings with non-zero beauty are ["aab", "aabc", "aabcb", "abcb", "bcb"], each with beauty equal to 2.
    Example 2:

    Input: s = "aabcbaa"
    Output: 17
    Explanation: The substrings with non-zero beauty are ["aabcb", "aabcba", "aabcb", "abcb", "bcb", "aabcbaa", "aabcba"], each with beauty equal to 2.
*/

int beautySum(string s) {
    
    // int minFreq = 0;
    // int maxFreq = 0;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        vector<int> count(26, 0);
        for(int j = i; j < n; j++){
            int ind = s[j] - 'a';
            count[ind]++;
            // if(minFreq == 0) minFreq = 1;
            // else minFreq = min(minFreq, count[ind]);
            // if(maxFreq == 0) maxFreq = 1;
            // else maxFreq = max(maxFreq, count[ind]);
            // if(maxFreq - minFreq > 0) ans += maxFreq - minFreq;
            // // minFreq = min(minFreq, )

            int minFreq = INT_MAX;
            int maxFreq = INT_MIN;
            
            for (int k = 0; k < 26; k++) {
                if (count[k] > 0) { 
                    minFreq = min(minFreq, count[k]);
                    maxFreq = max(maxFreq, count[k]);
                }
            }
            
            ans += maxFreq - minFreq;
        }
    }

    return ans;
}


int main(){
    string s = "aabcb";
    cout << beautySum(s) << endl;
    return 0;
}