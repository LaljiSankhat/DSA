#include <bits/stdc++.h>
using namespace std;


// nsum problem will be solved using two pointer approach like 2 sum and 3 sum and 4 sum 


// this will always gives TLE for large test cases
void f(vector<int> &nums, vector<int> &temp, set<vector<int>> &st, int k, int target, int lastIndex){
    if(k == 1) {
        for(int i = lastIndex; i < nums.size(); i++){
            if(nums[i] == target){
                temp.push_back(nums[i]);
                st.insert(temp);
                temp.pop_back();
            }
        }
        return;
    } else {
        for(int i = lastIndex; i < nums.size(); i++){
            temp.push_back(nums[i]);
            f(nums, temp, st, k - 1, target - nums[i], i + 1);
            temp.pop_back();
        }
    }
}

vector<vector<int>> nsum(vector<int> &nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    set<vector<int>> st;
    vector<int> temp;
    int lastIndex = 0;
    f(nums, temp, st, 3, 0, lastIndex);
    for(auto it : st){
        res.push_back(it);
    }
    return res;
}


int main(){
    vector<int> nums = {0,0,0};
    vector<vector<int>> res = nsum(nums);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}