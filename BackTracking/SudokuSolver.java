

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
 */
public class SudokuSolver {
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
    private static void solve(char[][] board,int row,int col,char[][] grid){
        int n = board.length;
        // base case
        if(row == n){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    grid[i][j] = board[i][j];
                }
            }
            return;
        }

        if(board[row][col] != '.'){
            if(col != n-1){
                solve(board,row,col+1,grid);
            }else{
                solve(board,row+1,0,grid);
            }
        }else{ //board[row][col] == '.'
            for(char ch = '1'; ch <= '9'; ch++){
                if(isValid(board,row,col,ch)) {
                    board[row][col] = ch;
                    if(col != n-1){
                        solve(board,row,col+1,grid);
                    }else{
                        solve(board,row+1,0,grid);
                    }
                    board[row][col] = '.'; // backtracking
                }
            }

        }
    }
    public static void solveSudoku(char[][] board){
        int n = board.length;
        char[][] grid = new char[n][n];
        solve(board,0,0,grid);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(grid[i][j]+" ");
            }
            System.out.println();
        }
    }

    // method two without grid
    /*
    class Solution {
    static int check = 0;
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
    private static void solve(char[][] board,int row,int col){
        // base case
        if(row == 9){
            check = 1;
            return;
        }

        if(board[row][col] != '.'){
            if(col != 8){
                solve(board,row,col+1);
            }else{
                solve(board,row+1,0);
            }
        }else{ //board[row][col] == '.'
            for(char ch = '1'; ch <= '9'; ch++){
                if(isValid(board,row,col,ch)) {
                    board[row][col] = ch;
                    if(col != 8){
                        solve(board,row,col+1);
                    }else{
                        solve(board,row+1,0);
                    }
                    if(check == 1) return;
                    board[row][col] = '.'; // backtracking
                }
            }

        }
    }
    public static void solveSudoku(char[][] board){
        solve(board,0,0);
        check = 0;

    }
}
     */
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
        solveSudoku(board);
    }
}
