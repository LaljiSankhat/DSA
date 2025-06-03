#include <bits/stdc++.h>
using namespace std;


// leetcode 1298. Maximum Candies You Can Get from Boxes

bool keyAvailable(int key, vector<int>& nums){
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == key) return true;
    } 
    return false;
}

int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

    int n = status.size();
    vector<bool> hasKey(n, false), visited(n, false), hasBox(n, false);
    queue<int> q;
    
    for (int box : initialBoxes) {
        hasBox[box] = true;
        if (status[box] == 1) {
            q.push(box);
            visited[box] = true;
        }
    }

    int ans = 0;

    while(!q.empty()){
        int box = q.front();
        q.pop();
        ans += candies[box];

        // for(int i = 0; i < containedBoxes[box].size(); i++){
        //     int cBox = containedBoxes[box][i];

        //     if((status[cBox] == 1 || keyAvailable(cBox, keys[box])) && !vis[cBox]){
        //         q.push({cBox, candies[cBox]});
        //         vis[cBox] = 1;
        //     }
        // }

        // for(int i = 0; i < keys[box].size(); i++){
        //     int cBox = keys[box][i];
        //     if(!vis[cBox]){
        //         q.push({cBox, candies[cBox]});
        //         vis[cBox] = 1;
        //     }
        // }

        // Get keys
        for (int k : keys[box]) {
            hasKey[k] = true;
            if (hasBox[k] && !visited[k] && status[k] == 0) {
                q.push(k);
                visited[k] = true;
                status[k] = 1;  // unlock it
            }
        }

        // Get contained boxes
        for (int b : containedBoxes[box]) {
            hasBox[b] = true;
            if ((status[b] == 1 || hasKey[b]) && !visited[b]) {
                q.push(b);
                visited[b] = true;
                status[b] = 1;  // unlock if you have key
            }
        }
    }

    return ans;
}


int main(){
    vector<int> status = {1,1,1}; 
    vector<int> candies = {100,1,100};
    vector<vector<int>> keys = {{},{0, 2},{}}; 
    vector<vector<int>> containedBoxes = {{}, {},{}}; 
    vector<int> initialBoxes = {1};
    int ans = maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    cout << ans << endl;
    return 0;
}