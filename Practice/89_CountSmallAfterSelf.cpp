#include <bits/stdc++.h>
using namespace std;


// leetcode 315. Count of Smaller Numbers After Self



void merge(vector<pair<int, int>>& arr, int l, int mid, int r, vector<int>& ans) {
    vector<pair<int, int>> temp;
    int i = l, j = mid + 1;
    int right_count = 0;

    while (i <= mid && j <= r) {
        if (arr[i].first <= arr[j].first) {
            ans[arr[i].second] += right_count;
            temp.push_back(arr[i]);
            i++;
        } else {
            right_count++;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        ans[arr[i].second] += right_count;
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = l; k <= r; k++) {
        arr[k] = temp[k - l];
    }
}

void mergeSort(vector<pair<int, int>>& arr, int l, int r, vector<int>& ans) {
    if (l >= r) return;

    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, ans);
    mergeSort(arr, mid + 1, r, ans);
    merge(arr, l, mid, r, ans);
}

vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 0);
    vector<pair<int, int>> arr;  // {num, index}
    for (int i = 0; i < n; i++) {
        arr.push_back({nums[i], i});
    }

    mergeSort(arr, 0, n - 1, ans);
    return ans;
}



int main(){
    vector<int> nums = {5,2,6,1};
    vector<int> ans = countSmaller(nums);
    for(int num : ans){
        cout << num << " ";
    }
    return 0;
}