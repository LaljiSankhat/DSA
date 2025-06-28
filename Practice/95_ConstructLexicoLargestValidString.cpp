#include <bits/stdc++.h>
using namespace std;


// leetcode 1718. Construct the Lexicographically Largest Valid Sequence

bool findLargestArray(vector<int> &res, vector<bool> &vis, int pos, int n){
    if(pos == 2 * n - 1) return true;
    if(res[pos] != 0){
        return findLargestArray(res, vis, pos + 1, n);
    }


    // try all unused values
    for(int i = n; i >= 1; i--){
        if(vis[i]) continue;

        vis[i] = 1;
        res[pos] = i;

        if(i == 1 and findLargestArray(res, vis, pos+1, n))
            return true;
        if(i > 1 and (pos + i) < (2*n - 1) and res[pos+i] == 0){
            res[pos+i] = i;
            if(findLargestArray(res, vis, pos + 1, n))
                return true;
            res[pos+i]=0;
        }
        vis[i] = false;
        res[pos] = 0;
    }

    return false;

}


vector<int> constructDistancedSequence(int n) {
    vector<int> res(2 * n - 1, 0);
    vector<bool> vis(n + 1, 0);

    findLargestArray(res, vis, 0, n);

    return res;
}



int main(){
    int n = 5;
    vector<int> ans = constructDistancedSequence(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
