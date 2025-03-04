#include <bits/stdc++.h>
using namespace std;


// leetcode 907. Sum of Subarray Minimums

vector<int> nextSmallerElement(vector<int> &nums){
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        if(!st.empty()){
            nse[i] = st.top();
        }
        st.push(i);        
    }

    return nse;
}

vector<int> prevSmallerElement(vector<int> &nums){
    int n = nums.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }
        if(!st.empty()){
            pse[i] = st.top();
        }
        st.push(i);        
    }

    return pse;
}

int sumOfSubarrayMinimums(vector<int> &nums){
    int n = nums.size();
    vector<int> nse = nextSmallerElement(nums);
    vector<int> pse = prevSmallerElement(nums);

    int ans = 0;
    int MOD = 1e9 + 7;
    for(int i = 0; i < n; i++){
        ans = (ans + ((nse[i] - i) * (i - pse[i])) * nums[i]) % MOD;
    }
    return ans;
}

int main(){
    vector<int> nums = {3, 1, 2, 4};
    cout << sumOfSubarrayMinimums(nums) << endl;
    return 0;
}