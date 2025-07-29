#include <bits/stdc++.h>
using namespace std;


// leetcode 140. Word Break II

vector<string> wordBreak(string s, vector<string>& wordDict) {

}


int main(){
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    vector<string> ans = wordBreak(s, wordDict);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}