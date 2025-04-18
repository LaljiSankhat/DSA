#include <bits/stdc++.h>
using namespace std;


// leetcode 38. Count and Say

string helper(string s){
    string res = "";

    for(int i = 0; i < s.size(); i++){
        int cnt = 1;
        while(i < s.size() - 1 && s[i] == s[i + 1]){
            cnt++;
            i++;
        }
        res += to_string(cnt) + s[i];
    }
    return res;
}

string countAndSay(int n){
    if(n == 1) return "1";
    string s = countAndSay(n - 1);
    return helper(s);
}


int main(){
    cout << helper("1211") << endl; // 111221
    return 0;
}