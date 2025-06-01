#include <bits/stdc++.h>
using namespace std;


// leetcode 2929. Distribute Candies Among Children II

// TLE
long long distributeCandies(int n, int limit) {

    int count = 0;
    for(int i = 0; i <= limit; i++){
        for(int j = 0; j <= n - i && j <= limit; j++){
            if((n - i - j) <= limit) count++;
        }
    }

    return count;
}

// optimised 
long long distributeCandiesOptimised(int n, int limit) {

    long long res = 0;
    for (int i = 0; i <= min(limit, n); i++) {
        if (n - i <= 2 * limit)
            res += min(n - i, limit) - max(0, n - i - limit) + 1;
    }
    return res;
}


int main(){
    int n = 3, limit = 3;
    cout << distributeCandies(n, limit) << endl;
    return 0;
}