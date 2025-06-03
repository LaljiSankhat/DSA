#include <bits/stdc++.h>
using namespace std;


// leetcode 76. Minimum Window Substring

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int> hash(256, 0);

    int l = 0, r = 0;
    int minLength = 1e9;
    int startIndex = -1;
    int count = 0; // no of potive hash decreased 

    // preinsertion of t elements 
    for(int i = 0; i < m; i++){
        hash[t[i]]++;
    }

    while(r < n){
        if (hash[s[r]] > 0) count++;
        hash[s[r]]--;
        while(count == m){
            if(r - l + 1 < minLength){
                minLength = r - l + 1;
                startIndex = l;
            }
            hash[s[l]]++;
            if(hash[s[l]] > 0) count--;
            l++;
        }
        r++;
    }

    return startIndex != -1 ? s.substr(startIndex, minLength) : "";
}


int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";   
    cout << minWindow(s, t) << endl;
    return 0;
}