#include <bits/stdc++.h>
using namespace std;


// leetcode 2311. Longest Binary Subsequence Less Than or Equal to K


// we check from back if 0 then we include because it doesn't exceed k
// if 1 then we check if no of bits is not exceded and sum is not exceed  k thne we include 1
int longestSubsequence(string s, int k) {
    int sm = 0;
    int cnt = 0;

    // to find no of bits required to represent k in binary we use this
    // it is equavalent to int bits = floor(log2(k)) + 1;
    int bits = 32 - __builtin_clz(k); 
    for (int i = 0; i < s.size(); ++i) {
        char ch = s[s.size() - 1 - i];
        if (ch == '1') {
            if (i < bits && sm + (1 << i) <= k) {
                sm += 1 << i;
                cnt++;
            }
        } else {
            cnt++;
        }
    }
    return cnt;
}


int main(){
    string s = "1001010";
    int k = 5;
    cout << longestSubsequence(s, k) << endl;
    return 0;
}