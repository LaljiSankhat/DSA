#include <bits/stdc++.h>
using namespace std;


// leetcodde ; 1922 


long countGoodNumbers(long n){
    long ans = 1;
    int MOD = 1e9 + 7;

    for (int i = 0; i < n; i++){
        if (i % 2 == 0) {
            ans = (5 * ans);
        }
        else ans = (4 * ans);
    }

    return ans; 
}


int main(){
    cout << countGoodNumbers(4) << endl;
    return 0;
}