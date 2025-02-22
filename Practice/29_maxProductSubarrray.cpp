#include <bits/stdc++.h>
using namespace std;



int maxProduct(vector<int> &nums){
    int maxProd = nums[0]; // Store the maximum product
    int leftProd = 1, rightProd = 1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        // Left pass
        leftProd *= nums[i];
        maxProd = max(maxProd, leftProd);
        if (nums[i] == 0) leftProd = 1; // Reset if 0 encountered
        
        // Right pass
        rightProd *= nums[n - 1 - i];
        maxProd = max(maxProd, rightProd);
        if (nums[n - 1 - i] == 0) rightProd = 1; // Reset if 0 encountered
    }

    return maxProd;
}

int main(){
    vector<int> nums = {-3, -1, -1};
    cout << maxProduct(nums);
    return 0;
}