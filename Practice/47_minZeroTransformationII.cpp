#include <bits/stdc++.h>
using namespace std;


// leetcode 3356. Zero Array Transformation II
// this giving TLE 
int minZeroArray2(vector<int> &nums, vector<vector<int>> &queries){
    unordered_map<int, int> mp;

    for(int i = 0; i < nums.size(); i++){
        mp[i] = nums[i];
    }

    int count = 0;

    for(int i = 0; i < queries.size(); i++){
        int l = queries[i][0];
        int r = queries[i][1];
        int val = queries[i][2];

        for(int k = l; k <= r; k++){
            if(mp.find(k) != mp.end()){
                if(mp[k] >= val) mp[k] = mp[k] - val;
                else mp[k] = 0;                
                if(mp[k] == 0) mp.erase(k);
            }
        }
        count++;
        if(mp.empty()) return count;
    }
    return -1;
}

bool canTransform(vector<int> &nums, vector<vector<int>> &queries, int k){
    int n = nums.size();
    int sum = 0;
    vector<int> diffArray(n + 1);

    for(int i = 0; i < k; i++){
        int start = queries[i][0];
        int end = queries[i][1];
        int val = queries[i][2];
        diffArray[start] += val;
        diffArray[end + 1] -= val;
    }

    for(int i = 0; i < n; i++){
        sum += diffArray[i];
        if(sum < nums[i]) return false;
    }
    return true;
}

int minZeroArray(vector<int> &nums, vector<vector<int>> &queries){
    int n = nums.size();
    int left = 0;
    int right = queries.size() - 1;

    if(!canTransform(nums, queries, right)) return -1;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(canTransform(nums, queries, mid)){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main(){
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2,1}, {0, 2, 1}, {1,1,3}};
    cout << minZeroArray(nums, queries) << endl;
    return 0;
}