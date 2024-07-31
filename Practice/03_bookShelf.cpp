#include <bits/stdc++.h>
using namespace std;

// 1105. Filling Bookcase Shelves

int f(int i, int h, int w, int sw, vector<vector<int>>& books){
    if(i < 0) return h;

    int putAbove = h + f(i - 1, books[i][1], sw - books[i][0], sw, books);
    int putInRow = 1e9;
    if(books[i][0] <= w){
        putInRow = f(i - 1, max(h, books[i][1]), w - books[i][0], sw, books);
    }

    return min(putAbove, putInRow);
}

int fDp(int i, int h, int w, int sw, vector<vector<int>>& books, vector<vector<int>> &dp) {
    if (i < 0)
        return h;
    if(dp[i][w] != -1) return dp[i][w];

    int putAbove = h + fDp(i - 1, books[i][1], sw - books[i][0], sw, books, dp);
    int putInRow = 1e9;
    if (books[i][0] <= w) {
        putInRow =
            fDp(i - 1, max(h, books[i][1]), w - books[i][0], sw, books, dp);
    }

    return dp[i][w] = min(putAbove, putInRow);
}

int fTab(int sw, vector<vector<int>>& books){
    int n = books.size();
    vector<vector<int>> dp(n + 1, vector<int>(sw + 1, INT_MAX));

    for (int w = 0; w <= sw; ++w) {
        dp[0][w] = 0;
    }

    for(int i = 1; i < n; i++){
        for(int w = 0; w <= sw; w++){
            dp[i][w] = dp[i - 1][sw] + books[i - 1][1];
            
            // Put the current book in the current row if it fits
            if (w >= books[i - 1][0]) {
                dp[i][w] = min(dp[i][w], dp[i - 1][w - books[i - 1][0]]);
            }
        }
    }

    int result = INT_MAX;
    for (int w = 0; w <= sw; ++w) {
        result = min(result, dp[n][w]);
    }
    
    return result;
}

int main(){
    vector<vector<int>> books = {{1, 1}, {2, 3}, {2, 3}, {1, 1},{1, 1}, {1, 1}, {1, 2}};
    int shelfWidth = 4;
    int n = books.size();

    cout << f(n - 1, 0, shelfWidth, shelfWidth, books) << endl;
    cout << fTab(shelfWidth, books) << endl;
    return 0;
}