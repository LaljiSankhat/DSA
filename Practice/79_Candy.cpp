#include <bits/stdc++.h>
using namespace std;


// leetcode 135. Candy


int candy(vector<int>& ratings) {
    // int n = ratings.size();
    // vector<int> candies(n, 0);
    // vector<vector<int>> arr;
    // for(int i = 0; i < n; i++){
    //     arr.push_back({ratings[i], i});
    // } 
    // sort(arr.begin(), arr.end());

    // for(int i = 0; i < n; i++){
    //     cout << arr[i][0] << " " << arr[i][1] << endl;
    // }

    // int ans = 0;

    // for(int i = 0; i < arr.size(); i++){
    //     int rat = arr[i][0];
    //     int ind = arr[i][1];

    //     int left = 0;
    //     int right = 0;
    //     if(ind > 0) left = candies[ind - 1];
    //     if(ind < n - 1) right = candies[ind + 1];

    //     int leftRating = rat;
    //     int rightRating = rat;
    //     if(ind > 0) leftRating = ratings[ind - 1];
    //     if(ind < n - 1) rightRating = ratings[ind + 1];

    //     if(min(leftRating, rightRating) < rat){
    //         candies[ind] = max(left, right) + 1;
    //     } else{
    //         candies[ind] = 1;
    //     }

    //     ans += candies[ind];
    // }

    // for(int i = 0; i < candies.size(); i++){
    //     cout << candies[i] << " ";
    // }
    // return ans;

    int n = ratings.size();
    vector<int> candies(n, 1);
    int cnt = 0;
    
    for (int i = 1; i < n; i++) 
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
    
    for (int i = n - 1; i > 0; i--) {
        if (ratings[i - 1] > ratings[i])
            candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
        cnt += candies[i - 1];
    }
    return cnt + candies[n - 1];
}


int main(){
    vector<int> ratings = {29,51,87,87,72,12};
    int ans = candy(ratings);
    cout << ans << endl;
    return 0;
}