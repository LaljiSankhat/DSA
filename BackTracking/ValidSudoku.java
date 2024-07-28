
/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
Input: board =
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board =
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8.
 Since there are two 8's in the top left 3x3 sub-box, it is invalid.



 */

public class ValidSudoku { // leetcode 46
    private static boolean isValid(char[][] board,int row,int col,char num){
        // check row
        for(int j = 0; j < board.length; j++){
            if(board[row][j] == num) return  false;
        }
        // check col
        for(int i = 0; i < board.length; i++){
            if(board[i][col] == num) return false;
        }
        // check 3x3 grid
        int sRow = (row / 3)*3;
        int sCol = (col / 3)*3;
        for(int i = sRow; i < sRow+3; i++){
            for(int j = sCol; j < sCol + 3; j++){
                if(board[i][j] == num) return false;
            }
        }
        return true;
    }
    public static boolean isValidSudoku(char[][] board){
        int n = board.length;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.') continue;
                char num = board[i][j];
                board[i][j] = '.';
                if(isValid(board,i,j,num) == false) return false;
                board[i][j] = num;
            }
        }
        return true;
    }
    public static void main(String[] args) {
       char[][] board = {{'5','3','.','.','7','.','.','.','.'},
                        {'6','.','.','1','9','5','.','.','.'},
                        {'.','9','8','.','.','.','.','6','.'},
                         {'8','.','.','.','6','.','.','.','3'},
                        {'4','.','.','8','.','3','.','.','1'},
                        {'7','.','.','.','2','.','.','.','6'},
                         {'.','6','.','.','.','.','2','8','.'},
                         {'.','.','.','4','1','9','.','.','5'},
                         {'.','.','.','.','8','.','.','7','9'}};
        System.out.println(isValidSudoku(board));
    }
}
