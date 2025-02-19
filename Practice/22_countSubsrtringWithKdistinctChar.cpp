#include <bits/stdc++.h>
using namespace std;


// count of substrings with exactly k distinct characters

/*
Given a string s of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Examples :

Input: s = "aba", k = 2
Output: 3
Explanation: The substrings are: "ab", "ba" and "aba".
Input: s = "abaaca", k = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a".
Input: s = "cdad", k = 4
Output: 0
*/


int countSubstringWithKDistinct(string s, int k){
    int n = s.size();
    int l = 0, count = 0;
    unordered_map<char, int> mp;

    for (int r = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp.size() > k) { // Shrink window if distinct characters > k
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }

        if (mp.size() == k) {
            // Count all valid substrings ending at r
            int temp = l;
            unordered_map<char, int> tempMap = mp;
            
            while (tempMap.size() == k) {
                count++;
                tempMap[s[temp]]--;
                if (tempMap[s[temp]] == 0) {
                    tempMap.erase(s[temp]);
                }
                temp++;
            }
        }
    }
    return count;
}



int countSubStringAtMostK(string s, int k){
    int n = s.size();
    int l = 0, count = 0;
    unordered_map<char, int> mp;

    for (int r = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp.size() > k) { // Shrink window if distinct characters > k
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }
        count += r - l + 1;
    }
    return count;
}

int countSubstringWithKDistinct2(string s, int k){
    return countSubStringAtMostK(s, k) - countSubStringAtMostK(s, k - 1);
}
int main(){
    string s = "abaaca";
    int k = 1;
    cout << countSubstringWithKDistinct2(s, k) << endl;
    return 0;
}