#include <bits/stdc++.h>
using namespace std;


/*
    885. Spiral Matrix III
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 

Example 1:


Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
Example 2:


Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 

Constraints:

1 <= rows, cols <= 100
0 <= rStart < rows
0 <= cStart < cols
*/

bool isValid(int i, int j, int rows, int cols){
    return i >= 0 && j >= 0 && i < rows && j < cols;
}

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    int moveLR = 0;
    int moveUD = 0;
    vector<vector<int>> ans;
    int num = 0;

    ans.push_back({rStart, cStart});
    num++;

    int endNum = rows * cols;

    while(num != endNum){
        // move to the right
        for(int i = 0; i <= moveLR; i++){
            if(isValid(rStart, cStart + 1, rows, cols)){
                ans.push_back({rStart, cStart + 1});
                num++;
            }
            cStart++;
        }
        moveLR++;

        // move to the down
        for(int i = 0; i <= moveUD; i++){
            if(isValid(rStart + 1, cStart, rows, cols)){
                ans.push_back({rStart + 1, cStart});
                num++;
            }
            rStart++;
        }
        moveUD++;

        // move to the left
        for(int i = 0; i <= moveLR; i++){
            if(isValid(rStart, cStart - 1, rows, cols)){
                ans.push_back({rStart, cStart - 1});
                num++;
            }
            cStart--;
        }
        moveLR++;

        // move to the up
        for(int i = 0; i <= moveUD; i++){
            if(isValid(rStart - 1, cStart, rows, cols)){
                ans.push_back({rStart - 1, cStart});
                num++;
            }
            rStart--;
        }
        moveUD++;
    }

    return ans;
}


int main(){
    int rows = 5;
    int cols = 6;
    int rStart = 1;
    int cStart = 4;

    vector<vector<int>> ans = spiralMatrixIII(rows, cols, rStart, cStart);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
    return 0;
}