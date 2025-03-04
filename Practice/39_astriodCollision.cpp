#include <bits/stdc++.h>
using namespace std;


// leetcode 735. Asteroid Collision


vector<int> prevGreaterElement(vector<int> &nums){
    int n = nums.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++){
        while(!st.empty() && abs(nums[st.top()]) < abs(nums[i])){
            st.pop();
        }
        if(!st.empty()) pge[i] = st.top();
        st.push(i);
    }

    return pge;
}

// this is seemed wrong approach
vector<int> asteroidCollision(vector<int> &asteroids){
    int n = asteroids.size();
    vector<int> pge = prevGreaterElement(asteroids);
    vector<int> ans;

    int i = n - 1;
    while(i >= 0){
        if(asteroids[i] < 0 && pge[i] != -1 && asteroids[pge[i]] > 0){
            i = pge[i];
        }
        ans.insert(ans.begin(), asteroids[i]);
        i--;
    }

    return ans;
}


// another method
vector<int> astCollision(vector<int> &asteroids){
    int n = asteroids.size();

    // vector<int> ans;
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(asteroids[i] > 0) st.push(asteroids[i]);
        else {
            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) st.pop();
            if (!st.empty() && st.top() > 0 && st.top() == abs(asteroids[i])) {
                st.pop(); // Both asteroids destroy each other
            } else if (st.empty() || st.top() < 0) {
                st.push(asteroids[i]); // No collision, push the negative asteroid
            }
        }
    }

    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}




int main(){
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = astCollision(asteroids);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}