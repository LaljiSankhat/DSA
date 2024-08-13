#include <bits/stdc++.h>
using namespace std;


/*
    40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations 
in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

void helper(int i, int target, vector<int> &list, vector<int> &nums, set<vector<int>> &st){
    if(target == 0){
        st.insert(list);
        return;
    }
    if(i < 0 || target < 0) return;
    if(target == nums[i]){
        list.push_back(nums[i]);
        st.insert(list);
        list.pop_back();
        return;
    }

    if(nums[i] <= target){
        list.push_back(nums[i]);
        helper(i - 1, target - nums[i], list, nums, st);
        list.pop_back();
    }
    

    helper(i - 1, target, list, nums, st);    
}

void helper2(int i, int target, vector<int> &list, vector<int> &nums, vector<vector<int>> &ans){
    if (target == 0) {
        ans.push_back(list);
        return;
    }

    int n = nums.size();

    for(int k = i; k < nums.size(); k++){
        if(k > i && nums[k] == nums[k - 1]) continue;
        if(nums[k] > target) break;

        list.push_back(nums[k]);
        helper2(k + 1, target - nums[k], list, nums, ans);
        list.pop_back();
    }
}

vector<vector<int>> combinationSumII(vector<int> &nums, int target){
    vector<vector<int>> ans;
    vector<int> list;
    // set<vector<int>> st;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    // reverse(nums.begin(), nums.end());
    // helper(n - 1, target, list, nums, st);
    // for (auto it = st.begin(); it != st.end(); ++it) {
    //     ans.push_back(*it);
    // }

    helper2(0, target, list, nums, ans);

    return ans;
}


int main(){
    vector<int> nums = {4,1,1,4,4,4,4,2,3,5};
    int target = 10;

    vector<vector<int>> ans = combinationSumII(nums, target);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}