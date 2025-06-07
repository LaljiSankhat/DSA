#include <bits/stdc++.h>
using namespace std;


// leetcode 3170. Lexicographically Minimum String After Removing Stars


string clearStars(string s) {
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minHeap;    
    int n = s.size();
    
    for(int i = 0; i < n; i++){
        if(s[i] != '*'){
            minHeap.push({s[i], -i});
        } else {
            minHeap.pop();  
        }
    }
    vector<int> isValid(n, 0);
    while(!minHeap.empty()){
        auto it = minHeap.top();
        minHeap.pop();
        isValid[abs(it.second)] = 1;
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        if(isValid[i]) ans += s[i];
    }
    return ans;
}


int main(){
    string s = "aaba*";
    cout << clearStars(s) << endl;
    return 0;
}