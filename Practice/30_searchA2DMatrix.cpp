#include <bits/stdc++.h>
using namespace std;


// leetcode 240 : search in 2d matrix II 

bool search(vector<vector<int>> &nums, int target){
    int n = nums.size();
    int m = nums[0].size();
    int topRightCol = m - 1;
    int topRightRow = 0;
    

    while(topRightCol >= 0 && topRightCol < m && topRightRow >= 0 && topRightRow < n){
        if(nums[topRightRow][topRightCol] == target) return true;
        if(nums[topRightRow][topRightCol] > target) {
            topRightCol--;
        } else if(nums[topRightRow][topRightCol] < target){
            topRightRow++;
        }
    }

    return false;
}


int main(){
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;
    cout << search(matrix, target) << endl;
    return 0;
}