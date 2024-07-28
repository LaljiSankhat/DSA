#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

/*

   Problem statement
Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities.
(Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day.
As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days.
Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity.
 Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

Sample Input 1:
2
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90
Sample Output 1:
11
210
Explanation of sample input 1:
For the first test case,
One of the answers can be:
On the first day, Ninja will learn new moves and earn 5 merit points.
On the second day, Ninja will do running and earn 3 merit points.
On the third day, Ninja will do fighting and earn 3 merit points.
The total merit point is 11 which is the maximum.
Hence, the answer is 11.

For the second test case:
One of the answers can be:
On the first day, Ninja will learn new moves and earn 70 merit points.
On the second day, Ninja will do fighting and earn 50 merit points.
On the third day, Ninja will learn new moves and earn 90 merit points.
The total merit point is 210 which is the maximum.
Hence, the answer is 210.
Sample Input 2:
2
3
18 11 19
4 13 7
1 8 13
2
10 50 1
5 100 11
Sample Output 2:
45
110

*/

int ninjaTraining(int n, vector<vector<int>> &points, int last){
    int maxi = 0;
    if (n == 0){
        for (int i = 0; i <= 2; i++){
            if (i != n){
                maxi = max(maxi, points[n][i]);
            }
        }
        return maxi;
    }
    for (int i = 0; i < 3; i++){
        if (i != n){
            int res = points[n][i] + ninjaTraining(n - 1, points, i);
            maxi = max(maxi, res);
        }
    }
    return maxi;
}

// memoization

int ninjaTrainingDp(int n, vector<vector<int>> &points, int last, vector<vector<int>> &dp){
    int maxi = 0;
    if (dp[n][last] != -1)
        return dp[n][last];
    if (n == 0){
        for (int i = 0; i <= 2; i++){
            if (i != n){
                maxi = max(maxi, points[n][i]);
            }
        }
        return maxi;
    }
    for (int i = 0; i < 3; i++){
        if (i != last){
            int res = points[n][i] + ninjaTraining(n - 1, points, i);
            maxi = max(maxi, res);
        }
    }
    return dp[n][last] = maxi;
}

// Tabulation

int tab(int day, vector<vector<int>> &points, vector<vector<int>> &dp){
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][0], max(points[0][2], points[0][1]));

    // int last = 3;
    int n = 3;
    for (int day = 1; day < n; day++){
        for (int last = 0; last < 4; last++){
            dp[day][last] = 0;
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if (task != last){
                    int res = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], res);
                }
            }
            // dp[day][last] = maxi;
        }
    }
    return dp[day - 1][3];
}


// space optimization

int f(int n, vector<vector<int>> &points){
    vector<int> dp(4,0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][1], points[0][0]);
    dp[3] = max(points[0][0], max(points[0][2], points[0][1]));

    
    
    for (int day = 1; day < n; day++){
        vector<int> temp(4,0);
        for (int last = 0; last < 4; last++){
            temp[last] = 0;
            int maxi = 0;
            for (int task = 0; task < 3; task++){
                if (task != last){
                    int res = points[day][task] + dp[task];
                    temp[last] = max(temp[last], res);
                }
            }
            // dp[day][last] = maxi;
        }
        dp = temp;
    }
    return dp[3];
}

int main(){
    vector<vector<int>> points = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    vector<vector<int>> dp(points.size(), vector<int>(4, -1));
    cout << ninjaTraining(2, points, 3) << endl;
    cout << ninjaTrainingDp(2, points, 3, dp) << endl;
    cout << tab(3, points,dp) << endl;
    cout << f(3, points) << endl;
    return 0;
}