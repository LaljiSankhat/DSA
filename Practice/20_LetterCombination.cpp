#include <bits/stdc++.h>
using namespace std;


// leetcode : 17. Letter Combinations of a Phone Number
/*
    Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
    Return the answer in any order.
    A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/

vector<string> helper(vector<string> d1, vector<string> d2){
    vector<string> res;
    for(int i = 0; i < d1.size(); i++){
        for(int j = 0; j < d2.size(); j++){
            res.push_back(d1[i] + d2[j]);
        }
    }
    return res;
}

vector<string> letterCombinstion(string digits){
    if(digits.size() == 0) return {};
    vector<vector<string>> map = {{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"}, {"m", "n", "o"},
                                      {"p", "q", "r", "s"}, {"t", "u", "v"}, {"w", "x", "y", "z"}};

    queue<vector<string>> q;
    q.push({""});

    int digit = 0;

    while(digit < digits.size() && !q.empty()){
        vector<string> temp = q.front();
        q.pop();
        vector<string> d = map[digits[digit] - '0' - 2];
        digit++;
        q.push(helper(temp, d));
    }

    return q.front();
    
}

int main(){
    string digits = "23";
    vector<string> res = letterCombinstion(digits);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}