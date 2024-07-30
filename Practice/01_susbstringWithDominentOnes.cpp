#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    int n = s.size();
    int ones = 0; 
    int zeros = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(s[j] == '0') zeros++;
            if(s[j] == '1') ones++;
            if(ones != 0 && ones >= (zeros * zeros)) cnt++;
            cout << ones << zeros << cnt << endl;
        }
        ones = 0;
        zeros = 0;
    }
    return cnt;
    
}

int main(){
    string s = "00011";
    cout << numberOfSubstrings(s) << endl;
    return 0;
}