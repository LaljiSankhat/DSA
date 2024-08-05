#include <bits/stdc++.h>
using namespace std;


/*
    Problem statement
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.
A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, 
and same for a strictly descending order sequence.
For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the 
sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.
You are given an array 'arr' consisting of 'n' positive integers.
Find the length of the longest bitonic subsequence of 'arr'.

Example :
Input: 'arr' = [1, 2, 1, 2, 1]

Output: 3

Explanation: The longest bitonic subsequence for this array will be [1, 2, 1].
Please note that [1, 2, 2, 1] is not a valid bitonic subsequence, because the consecutive
2's are neither strictly increasing, nor strictly decreasing.
*/

/* Bitonic : first Increasing then Decreasing, it can also always increasing or always decreasing */


int longestBitonicSequence(vector<int> &arr, int n){
    vector<int> dp1(n, 1);

    for(int i = 1; i < n; i++){
        for(int prev = 0; prev < i; prev++){
            if(arr[i] > arr[prev] && dp1[prev] + 1 > dp1[i]){ // this is valid, this can be part of LIS
                dp1[i] = dp1[prev] + 1;
            }
        }
    }

    vector<int> dp2(n, 1);
    
    for(int i = n - 1; i >= 0; i--){
        for(int prev = n - 1; prev > i; prev--){
            if(arr[i] > arr[prev] && dp2[prev] + 1 > dp2[i]){ // this is valid, this can be part of LIS
                dp2[i] = dp2[prev] + 1;
            }
        }
    }

    int maxi = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }

    return maxi;
}

int main(){
    vector<int> nums = {1,7,4,8,16};
    int n = nums.size();
    cout << longestBitonicSequence(nums, n) << endl;
    return 0;
}