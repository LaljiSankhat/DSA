#include <bits/stdc++.h>
using namespace std;


/*
    Minimum Multiplications to reach End
Difficulty: MediumAccuracy: 48.94%Submissions: 107K+Points: 4
Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in 
the array and then mod operation with 100000 is done to get the new start.
Your task is to find the minimum steps in which end can be achieved starting from start. If it is 
not possible to reach end, then return -1.

Example 1:
Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30

Example 2:
Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
*/

// we keep multiplying till we get our answer
// but if number > 1,00,000 (10 ^ 5) then we took modulo to 10 ^ 5 then repeat procees till we get answer
// so we can reach between 0 to 99,999 nodes
// and we store no of operations as steps

int minimumMultiplicationToReachDestination(int src, int end, vector<int> arr){
    vector<int> dist(100000, 1e9);
    queue<pair<int, int>> q;
    dist[src] = 0;
    q.push({src, 0});
    int mod = 100000;

    while(!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(int i = 0; i < arr.size(); i++){
            int num = (node * arr[i]) % mod;
            if(steps + 1 < dist[num]){
                dist[num] = steps + 1;
                if(num == end) return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}

int main(){
    vector<int> arr = {3, 4, 65};
    int start = 7;
    int end = 66175;

    cout << minimumMultiplicationToReachDestination(start, end, arr) << endl;

    // TC = O(10 ^ 5 * N) n = size of arr
    return 0;
}