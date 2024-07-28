#include <bits/stdc++.h>
using namespace std;


// here all elements apear thrice except one number so we have to find that number

// to solve this we knoe that if ith bit is multiple of 3 then in ans that ith bit will not set
// it is not multiple of 3 then the ith bit is set

int singleNumberII(vector<int> &nums){
    int n = nums.size();

    int ans = 0;

    for(int bitIndex = 0; bitIndex < 32; bitIndex++){
        int count = 0;
        for(int i = 0; i < n; i++){
            if((nums[i] & (1 << bitIndex)) != 0) count++;
        }
        if(count % 3 != 0) ans += (1 << bitIndex);
    }

    return ans;
}

// method 2 by sorting

int sigleNumberIIWithSorting(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 1; i < n; i = i + 3){
        if(nums[i - 1] != nums[i]) return nums[i - 1];
    }

    return nums[n - 1];
}

// method 3 buckets

int sigleNumberIIWithBuckets(vector<int> &nums){
    int n = nums.size();
    int ones = 0, twos = 0;

    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }

    return ones;
}


int main(){
    vector<int> nums = {1, 1, 1, 2};
    cout << singleNumberII(nums) << endl;
    cout << sigleNumberIIWithSorting(nums) << endl;
    cout << sigleNumberIIWithBuckets(nums) << endl;
    return 0;
}