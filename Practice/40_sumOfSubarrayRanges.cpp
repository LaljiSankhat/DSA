#include <bits/stdc++.h>
using namespace std;

// 2104. Sum of Subarray Ranges

// so we can brak down problem such way that 
// sum of subarray ranges = sum of subarray maximums - sum of subarray minimums 


vector<int> nextSmallerElement(vector<int> &nums){
    int n = nums.size();
    vector<int> nse(n, n);
    stack<int> st;

    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
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

long long sumOfSubarrayMinimums(vector<int> &nums){
    int n = nums.size();
    vector<int> nse = nextSmallerElement(nums);
    vector<int> pse = prevSmallerElement(nums);

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + ((nse[i] - i) * (i - pse[i])) * nums[i]);
    }
    return ans;
}






vector<int> nextGreaterElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(i);
    }

    return nge;
}

vector<int> prevGreaterElement(vector<int> &nums) {
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }
        if (!st.empty()) {
            pge[i] = st.top();
        }
        st.push(i);
    }

    return pge;
}

long long sumOfSubarrayMaximums(vector<int> &nums) {
    int n = nums.size();
    vector<int> nge = nextGreaterElement(nums);
    vector<int> pge = prevGreaterElement(nums);

    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + ((i - pge[i]) * (nge[i] - i)) * nums[i]);
    }
    return ans;
}

long long sumOfSubarrayRanges(vector<int> &nums){
    return (long long)(sumOfSubarrayMaximums(nums) - sumOfSubarrayMinimums(nums));
}

int main(){
    vector<int> nums = {1, 3, 3};
    cout << sumOfSubarrayRanges(nums) << endl;
    return 0;
}