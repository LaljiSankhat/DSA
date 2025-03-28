#include <bits/stdc++.h>
using namespace std;


/*
    Find XOR of numbers from L to R.
Difficulty: EasyAccuracy: 50.0%Submissions: 24K+Points: 2
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:
Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).
*/

// to solve this we have to observe a pattern to find xor of N numbers
// if N % 4 == 1 ans = 1
// if N % 4 == 2 ans = N + 1
// if N % 4 == 3 ans = 0
// if N % 4 == 0 ans = N

int xorOfNnumbers(int n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n + 1;
    if(n % 4 == 3) return 0;
}

int findXorLtoR(int l, int r){
    int temp = xorOfNnumbers(l - 1);
    int temp2 = xorOfNnumbers(r);

    return temp xor temp2;
}
 

int main(){
    cout << findXorLtoR(4, 8) << endl;
    return 0;
}