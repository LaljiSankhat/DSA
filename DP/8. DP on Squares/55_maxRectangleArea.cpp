#include <bits/stdc++.h>
using namespace std;

/*
    85. Maximal Rectangle
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1 
1 0 0 1 0
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
 
Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

/* 
    here we will be given a matrix that contains only 1 and 0. we have to find maximum rectangle with only 1s
    and return area of that
*/

/* 
    To solve this we will use code and concept of largest histogram in rectangle question.
    we create histogram at every row then find max area by largest histogram method.
    if 0 then height of rectangle make 0 and 1 then increase the height of histogram.
*/

int largestRectangleArea(vector <int> &histo) {
    int maxA = 0;
    stack < int > st;
    int n = histo.size();
    for (int i = 0; i <= n; i++) {
    while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
        int height = histo[st.top()];
        st.pop();
        int width;
        if (st.empty())
            width = i;
        else
            width = i - st.top() - 1;
        maxA = max(maxA, width * height);
    }
    st.push(i);
    }
    return maxA;
}


int maxAreaRectangle(vector<vector<int>> &matrix, int n, int m){
    int maxArea = 0;
    vector<int> height(m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}


int main(){
    vector<vector<int>> arr = {{1, 0, 1, 0, 0}, {1, 0, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 0, 0, 1, 0}};
    int n = arr.size();
    int m = arr[0].size();
    cout << maxAreaRectangle(arr, n, m) << endl;
    return 0;
}