



# leetcode 873. Length of Longest Fibonacci Subsequence

def longestFibbonacciSubsequence(arr) -> int:
    arr_set = set(arr)
    res = 0

    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            pre, cur = arr[i], arr[j]
            nxt = pre + cur
            length = 2
            while nxt in arr_set:
                prev, cur = cur, nxt
                nxt = prev + cur
                length += 1
                res = max(res, length)



    return res

def longestFibbonacciSubsequenceDp(arr) -> int:
    arr_map = {n:i for i,n in enumerate(arr)}
    res = 0

    dp = [[0] * len(arr) for _ in range(len(arr))] # (i, j) -> length of longest subseq

    for i in reversed(range(len(arr) - 1)):
        for j in reversed(range(i + 1, len(arr))):
            pre, cur = arr[i], arr[j]
            nxt = pre + cur
            length = 2
            if nxt in arr_map:
                length = 1 + dp[j][arr_map[nxt]]
                res = max(res, length)
            dp[i][j] = length


    return res


arr = [1, 2, 3, 4, 5, 6, 7, 8]
print(longestFibbonacciSubsequence(arr))
print(longestFibbonacciSubsequenceDp(arr))










# #include <bits/stdc++.h>
# using namespace std;


# // 


# int LFSrecursion(int i, int pre2, int pre1, vector<int> &arr){
#     if(i >= arr.size()) return 0;

#     int take = 0, notTake = 0;
#     if(pre1 == -1 || pre2 == -1 || arr[i] == pre1 + pre2){
#         take = 1 + LFSrecursion(i + 1, pre1, arr[i], arr);
#     }
#     notTake = LFSrecursion(i + 1, pre2, pre1, arr);

#     return max(take, notTake);    
# }

# int LFSmemoization(int i, int pre2, int pre1, vector<int> &arr, vector<vector<vector<int>>> &dp){
#     if(i >= arr.size()) return 0;
#     if(dp[i][pre2 + 1][pre1 + 1] != -1) return dp[i][pre2 + 1][pre1 + 1];

#     int take = 0, notTake = 0;
#     if(pre1 == -1 || pre2 == -1 || arr[i] == arr[pre1] + arr[pre2]){
#         take = 1 + LFSmemoization(i + 1, pre1, i, arr, dp);
#     }
#     notTake = LFSmemoization(i + 1, pre2, pre1, arr, dp);

#     return dp[i][pre2 + 1][pre1 + 1] = max(take, notTake);
# }

# int LFStabulation(vector<int> &arr){
#     int n = arr.size();
#     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));

#     // for(int i = )
# }

# int longestFibbonacciSubsequence(vector<int> &arr){
#     int n = arr.size();
#     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
#     cout << LFSmemoization(0, -1, -1, arr, dp) << endl;
#     return LFSrecursion(0, -1, -1, arr);
# }

# int main(){
#     vector<int> arr = {1,3,7,11,12,14,18};
#     cout << longestFibbonacciSubsequence(arr) << endl;
#     return 0;
# }