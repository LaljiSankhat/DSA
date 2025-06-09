#include <bits/stdc++.h>
#define ll long long
using namespace std;


// leetcode 440. K-th Smallest in Lexicographical Order


// This gives TLE
int findKthNumber(int n, int k) {
    priority_queue<string, vector<string>, greater<string>> pq;
    
    for(int i = 1; i <= n && i <= 9; i++){
        pq.push(to_string(i));
    }

    while(!pq.empty()){
        string t = pq.top();
        pq.pop();
        k--;
        int num = stoi(t);
        if(k == 0) return num;

        for(int i = 0; i <= 9; i++){
            string temp = t + to_string(i);
            if (stoll(temp) <= n) {
                pq.push(temp);
            }
        }
    }
    return -1;
}


// optimized solution
int countSteps(int n, ll pre1, ll pre2){
    int steps = 0;
    while(pre1 <= n){
        steps += min((ll)n + 1, pre2) - pre1;
        pre1 *= 10;
        pre2 *= 10;
    }
    return steps;
}

int findKthNumberOptimized(int n, int k){
    int curr = 1;
    k -= 1;


    while(k){
        int steps = countSteps(n, curr, curr + 1);
        if(steps <= k){
            curr++;
            k -= steps;
        } else {
            curr *= 10;
            k--;
        }
    }
    return curr;
}


int main(){
    int n = 13;
    int k = 2;
    cout << findKthNumber(n, k) << endl;
    return 0;
}