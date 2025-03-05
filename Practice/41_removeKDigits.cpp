#include <bits/stdc++.h>
using namespace std;


// leetcode 402. Remove K Digits


// so here we are stack if we have large test case then it will give us MLE
string removeKdigits(string num, int k){
    int n = num.size();
    if(n == k) return "0";

    stack<char> st;

    for(int i = 0; i < n; i++){
        if(k > 0){
            while(!st.empty() && st.top() - '0' > num[i] - '0' && k > 0){
                st.pop();
                k--;
            }
        }
        st.push(num[i]);
    }

    string ans = "";
    while(!st.empty()){
        ans = st.top() + ans;
        st.pop();
    }
    int i = 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }
    ans = ans.substr(i);
    return ans;
}


// so to overcome MLE we use string instead of stack 
string removeKdigitsWithStringAsStack(string num, int k) {
    string ans = "";
    int n = num.size();
    if(n == k) return "0";

    for (char c : num) {
        // Remove characters from ans if they are greater than current char and we still have deletions left
        while (!ans.empty() && ans.back() > c && k > 0) {
            ans.pop_back();
            k--;
        }
        ans.push_back(c);
    }

    // Remove remaining `k` digits from the end if necessary
    while (k > 0 && !ans.empty()) {
        ans.pop_back();
        k--;
    }

    // Remove leading zeros
    int i = 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }
    ans = ans.substr(i);

    // If the string is empty, return "0"
    return ans.empty() ? "0" : ans;
}

int main(){
    string num = "1432219";
    int k = 3;
    cout << removeKdigitsWithStringAsStack(num, k) << endl;
    return 0;
}