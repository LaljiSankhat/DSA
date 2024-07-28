
/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack
each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a
queen and an empty space, respectively.
Input: n = 4
Output: [[".Q..",
          "...Q",
          "Q...",
          "..Q."],

          ["..Q.",
          "Q...",
          "...Q",
          ".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NQueens {
    public static void main(String[] args) {
        int n = 4;
//        char[][] board = new char[n][n];
//        for(int i = 0; i < board.length; i++){
//            for(int j = 0; j < board[i].length;j++){
//                board[i][j] = '.';
//            }
//        }
        // nQueen(board,0);
        List<List<String>> st = new ArrayList<>();
        st = solveNQueens(n);
        System.out.println(st);

    }

    private static void nQueen(char[][] board, int row) {
        int n = board.length;
        // base case
        if(row == n){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n;j++){
                    System.out.print(board[i][j]);
                }
                System.out.println();
            }
            System.out.println();
            return;
        }
        // work and call
        for(int j = 0; j < n; j++){
            if(isSafe(board,row,j)){
                board[row][j] = 'Q';
                nQueen(board,row+1);
                // backtracking
                board[row][j] = '.';
            }
        }
    }

    private static boolean isSafe(char[][] board, int row, int col) {
        int n = board.length;
        // check the row
        for(int j = 0; j < board.length; j++){
            if(board[row][j] == 'Q') return  false;
        }
        // check col
        for(int i = 0; i < board.length; i++){
            if(board[i][col] == 'Q') return false;
        }
        int i = row;
        int j = col;
        // check north east
        while(i>=0 && j <n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        i = row;
        j = col;
        // check south west
        while(i < n && j >= 0){
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        i = row;
        j = col;
        //check north west
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        // check south east
        while(i < n && j < n){
            if(board[i][j] == 'Q') return false;
            i++;
            j++;
        }
        return true;
    }

    // method 2 of leetcode type
    public static List<List<String>> solveNQueens(int n){
        char[][] board = new char[n][n];
//        for(int i = 0; i < board.length; i++){
//            for(int j = 0; j < board[i].length;j++){
//                board[i][j] = '.';
//            }
//        }

        for (char[] chars : board) {
            Arrays.fill(chars, '.');
        }
        List<List<String>> ans = new ArrayList<>();
        nQueen2(board,0,ans);
        return ans;

    }

    private static void nQueen2(char[][] board, int row, List<List<String>> ans) {
        int n = board.length;
        // base case
        if(row == n){
            List<String> ll = new ArrayList<>();
            for(int i = 0; i < n; i++){
                String str = "";
                for(int j = 0; j < n;j++){
                    str += board[i][j];
                }
                ll.add(str);
            }
            ans.add(ll);
            return;
        }
        // work and call
        for(int j = 0; j < n; j++){
            if(isSafe(board,row,j)){
                board[row][j] = 'Q';
                nQueen2(board,row+1,ans);
                // backtracking
                board[row][j] = '.';
            }
        }
    }
}

/* n queens 2 leetcode
class Solution {
    public int totalNQueens(int n){
        char[][] board = new char[n][n];
        for (char[] chars : board) {
            Arrays.fill(chars, '.');
        }
        List<List<String>> ans = new ArrayList<>();
        nQueen2(board,0,ans);
        return ans.size();

    }
    private boolean isSafe(char[][] board, int row, int col) {
        int n = board.length;
        // check the row
        for(int j = 0; j < board.length; j++){
            if(board[row][j] == 'Q') return  false;
        }
        // check col
        for(int i = 0; i < board.length; i++){
            if(board[i][col] == 'Q') return false;
        }
        int i = row;
        int j = col;
        // check north east
        while(i>=0 && j <n){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        i = row;
        j = col;
        // check south west
        while(i < n && j >= 0){
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        i = row;
        j = col;
        //check north west
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row;
        j = col;
        // check south east
        while(i < n && j < n){
            if(board[i][j] == 'Q') return false;
            i++;
            j++;
        }
        return true;
    }

    private void nQueen2(char[][] board, int row, List<List<String>> ans) {
        int n = board.length;
        // base case
        if(row == n){
            List<String> ll = new ArrayList<>();
            for(int i = 0; i < n; i++){
                String str = "";
                for(int j = 0; j < n;j++){
                    str += board[i][j];
                }
                ll.add(str);
            }
            ans.add(ll);
            return;
        }
        // work and call
        for(int j = 0; j < n; j++){
            if(isSafe(board,row,j)){
                board[row][j] = 'Q';
                nQueen2(board,row+1,ans);
                // backtracking
                board[row][j] = '.';
            }
        }
    }
}
 */
