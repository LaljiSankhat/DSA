#include <bits/stdc++.h>
using namespace std;


// leetcode : 1980. Find Unique Binary String
/*
    Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

    Example 1:

    Input: nums = ["01","10"]
    Output: "11"
    Explanation: "11" is a binary string that is different from "01" and "10".
    Note that it does not matter if this answer is "00", "01", "10", or "11".
    Example 2:

    Input: nums = ["00","01"]
    Output: "11"
    Explanation: "11" is a binary string that is different from "00" and "01".
    Example 3:

    Input: nums = ["111","011","001"]
    Output: "101"
    Explanation: "101" is a binary string that is different from "111", "011", and "001".
*/


// this take 2 ** n time complexity
void findStrings(int n, string &s, set<string> &st){
    if(n == 0){
        st.insert(s);
        return;
    }

    s.push_back('0');
    findStrings(n - 1, s, st);
    s.pop_back();
    s.push_back('1');
    findStrings(n - 1, s, st);
    s.pop_back();
}


string findDifferentBinaryString(vector<string> &nums){
    int n = nums.size();
    set<string> st;
    string s = "";
    findStrings(n, s, st);
    for(int i = 0; i < n; i++){
        st.erase(nums[i]);
    }
    for(auto it : st){
        return it;
    }
    return "";
}


// for linear time complexity
// this solution is based on cantors diagonalization argument
string findDifferentBinaryString2(vector<string> &nums){
    int n = nums.size();
    string res = "";
    for(int i = 0; i < n; i++){
        if(nums[i][i] == '0'){
            res.push_back('1');
        } else {
            res.push_back('0');
        }
    }
    return res;
}


int main(){
    vector<string> nums = {"111","011","001"};
    cout << findDifferentBinaryString(nums);
    cout << findDifferentBinaryString2(nums);
    return 0;
}