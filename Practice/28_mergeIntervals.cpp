#include <bits/stdc++.h>
using namespace std;

// leetcode : 56. Merge Intervals
/*
    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> temp = intervals;
    sort(temp.begin(), temp.end());

    vector<vector<int>> ans;
    int n = temp.size();


    ans.push_back(temp[0]);

    for(int i = 1; i < n; i++){
        if(ans.back()[1] >= temp[i][0]){
            ans.back()[1] = max(ans.back()[1], temp[i][1]);
        } else {
            ans.push_back(temp[i]);
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> intervals = {{1,4},{0, 2},{3, 5}};
    vector<vector<int>> res = merge(intervals);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}