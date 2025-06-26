#include <bits/stdc++.h>
using namespace std;


//  leetcode 1931. Painting a Grid With Three Different Colors

/*
        No of rows = 1000 maximum
        Colors per cell = 3
        Color Combinations used:
            00: No color (White)
            01: Red
            10: Green
            11: Blue
        Cell per column = No of rows = 5
        TO represent 5 colors, each of 2 bits, total bits required = 10 bits
        Max value with 10 bits (all set-bits) = 1023

        Therefore, dimension of memoization state = No of Columns * Color combinations per column
        So, state_mem = 1000 * 1023 size
    */
int MOD = 1e9+7;
int state_mem[1000+2][1023];//1000 rows...1023 for all set-bits for mask of 10 bits
int countWays(int& m,int& n,int r,int c,int curr_state,int prev_state){
    if(c==n)    return 1;//Valid Painting Combination
    if(r==m)    return countWays(m,n,0,c+1,0,curr_state);//Goto next col
    if(r==0 and state_mem[c][prev_state]!=-1) return state_mem[c][prev_state];//Repeating subproblem

    /*
        up_color needs the most significant pair bits.
        Therefore, we need to shift (r-1) pairs
    */
    int up_color = 0;
    if(r>0) up_color = curr_state & 3;

    /*
        masking with 3 ,i.e, 11 in binary, just gets the pair bits in which we are interested.
        This turns OFF more significant pair bits.
    */
    int left_color = (prev_state >> ((m-r-1)*2)) & 3;

    //Try all colors
    int ways_to_color = 0;
    for(int color=1;color<=3;++color){
        if(color!=up_color and color!=left_color)
            ways_to_color = (ways_to_color + countWays(m,n,r+1,c,(curr_state<<2) + color,prev_state))%MOD;
    }
    if(r==0)
        state_mem[c][prev_state] = ways_to_color;
    return ways_to_color;
}
    

int colorTheGrid(int m, int n) {
    memset(state_mem,-1,sizeof(state_mem));
    return countWays(m,n,0,0,0,0);
}


int main(){
    int m = 1, n = 1;
    cout << colorTheGrid(m, n) << endl;
    return 0;
}