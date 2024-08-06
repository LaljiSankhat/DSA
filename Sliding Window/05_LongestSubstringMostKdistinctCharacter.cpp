#include <bits/stdc++.h>
using namespace std;


// given a string and value k
// return longest substring with atmost k distinct elements


int longestSubstringMostKdistinctCharacters(string s, int k){
    int n = s.size();
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp;

    while(r < n){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(mpp[s[l]]);
            l++;
        }
        if(mpp.size() <= k){
            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }

    return maxLen;
}


int main(){
    string s = "aaabbccd";  
    int k = 2;
    cout << longestSubstringMostKdistinctCharacters(s, k);
    return 0;
}