#include <bits/stdc++.h>
using namespace std;


// here we have to find the power set of given array


vector<vector<int>> generateSubsets(int n, int arr[]){
    int subsets = 1 << n;

    vector<vector<int>> ans;

    for(int i = 0; i < subsets; i++){
        vector<int> list;
        for(int bit = 0; bit < n; bit++){
            if((i & (1 << bit)) != 0){ // this means ith bit is set means we have to take the element
                list.push_back(arr[bit]);
            }
        }
        ans.push_back(list);
    }

    return ans;
}

int main(){
    int n = 3;
    int arr[] = {1, 2, 3};

    vector<vector<int>> ans = generateSubsets(n, arr);

    for(const auto &subset : ans) {
        for(auto it : subset) {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}