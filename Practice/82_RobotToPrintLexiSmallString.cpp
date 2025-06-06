#include <bits/stdc++.h>
using namespace std;


// leetcode 2434. Using a Robot to Print the Lexicographically Smallest String


string robotWithString(string s) {
    int n = s.size();
    
    vector<char> minCharToRight(n);
    minCharToRight[n - 1] = s[n - 1];

    for(int i = n - 2; i >= 0; i--){
        minCharToRight[i] = min(s[i], minCharToRight[i + 1]);
    }

    string t = "", p = "";

    int i = 0;
    while(i < n){
        t.push_back(s[i]);

        char minChar = (i + 1 < n) ? minCharToRight[i + 1] : s[i];

        while(!t.empty() && t.back() <= minChar){
            p += t.back();
            t.pop_back();
        }

        i++;
    }

    while(!t.empty()){
        p += t.back();
        t.pop_back();
    }
    return p;
    
}



int main(){
    string s = "zza";
    cout << robotWithString(s) << endl;
    return 0;
}