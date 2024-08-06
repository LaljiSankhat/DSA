#include <bits/stdc++.h>
using namespace std;


/*
    Fruit Into Baskets
You are visiting a farm that has a single row of fruit trees arranged from left to right. 
The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the 
amount of fruit each basket can hold. Starting from any tree of your choice, you must pick exactly one fruit 
from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.

Examples:

Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same 
in the 1st and 3rd baskets.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket 
as we would have to stop at thrid tree which would result in only 2 fruits collected.
*/

// similar Leetcode : 904. Fruit Into Baskets


// given an array of trees in which every tree has a type of fruit
// we have baskets in which we can store only single type fruit, can be more but single type only
// we have to take fruits consecutively from we start picking or we can not skip any fruit


// we can reformat question to : find max subarray with atmost 2 types of fruit


int fruitsInBasket(vector<int> &fruits){
    int n = fruits.size();
    int l = 0, r = 0, maxLen = 0;
    unordered_map<int, int> mpp;

    while(r < n){
        mpp[fruits[r]]++;
        if(mpp.size() > 2){ // then we move l also 
            mpp[fruits[l]]--;
            if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
            l++;
        }
        if(mpp.size() <= 2){
            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }

    return maxLen;
}



int main(){
    vector<int> fruits = {2, 1, 2};
    cout << fruitsInBasket(fruits);
    return 0;
}