package StackQuestios;

import java.util.Stack;

/*
   A celebrity is a person (condition 1) who is known to all but (condition 2) does not know anyone at a party. 
   If you go to a party of N people,find if there is a celebrity in the party or not.A square NxN matrix M[][] is 
   used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith
   person knows jth person. Here M[i][i] will always be 0.
   Note: Follow 0 based indexing.
   Follow Up: Can you optimize it to O(N)


   Input:
   N = 3
   M[][] = {{0 1 0},
            {0 0 0}, 
            {0 1 0}}
   Output: 1
   Explanation: 0th and 2nd person both
   know 1. Therefore, 1 is the celebrity. 
 */
public class CelebrityProblem {
    public static int celebrity(int [][]m,int n){
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; i++){
            st.push(i);
        }
        while(st.size() > 1){
            int v2 = st.pop();
            int v1 = st.pop();
            if(m[v1][v2] == 1) st.push(v2);
            else if(m[v2][v1] == 1) st.push(v1);
        }
        // int a = st.pop();
        // return a;
        if(st.size() == 0) return -1;
        int a = st.pop();
        for(int i=0; i<n; i++){
            if(m[a][i] == 1) return -1; // does not know anyone at a party.
        }
        for(int j = 0; j<n; j++){
            if(j != a && m[j][a] == 0){ //  who is known to all
                return -1;
            }
        }
        return a;
    }
    public static void main(String[] args) {
      int [][] arr = {{0,1,0},
                      {0,0,0},
                      {0,1,0}};
      int n = arr.length;
    //   System.out.println(n);
      int cel = celebrity(arr, n);
      System.out.println(cel);
    }
}
