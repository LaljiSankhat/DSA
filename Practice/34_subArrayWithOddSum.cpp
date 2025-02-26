#include <bits/stdc++.h>
using namespace std;


// leetcode 1524

int noOfSubArrayWithOddSum(vector<int> &arr){
    int n = arr.size();
    int odd = 0, even = 1;
    int curSum = 0;
    int ans = 0;
    int MOD = 1e9 + 7;

    for(int num : arr){
        curSum += num;
        if(curSum % 2 == 0){
            ans = (ans + odd) % MOD;
            even++;
        } else {
            ans = (ans + even) % MOD;
            odd++;
        }
    }
    return ans;    
}


int main(){
    vector<int> arr = {1, 3, 5};
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> arr3 = {1, 3, 6, 10, 15, 21, 28, 36, 45};
    vector<int> pre = {1, 4, 9};
    cout << noOfSubArrayWithOddSum(arr) << endl;
    return 0;
}