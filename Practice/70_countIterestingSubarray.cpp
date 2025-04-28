#include <bits/stdc++.h>
using namespace std;


// leetcode 2845. Count of Interesting Subarrays

long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    long long n = nums.size();
    long long pos = 0;
    long long arr = 0;
    long long pref_count = 0;

    unordered_map<long long, long long> freq;

    freq[0] = 1;
    while(pos < n){
        if(nums[pos] % modulo == k){
            pref_count++;
        }

        pref_count %= modulo;

        if(freq.count((pref_count - k + modulo) % modulo)){
            arr += freq[(pref_count - k + modulo) % modulo];
        }

        freq[pref_count]++;
        pos++;
    }

    return arr;
    
}

int main(){
    vector<int> nums = {3,2,4};
    int modulo = 2;
    int k = 1;
    cout << countInterestingSubarrays(nums, modulo, k) << endl;
    return 0;
}