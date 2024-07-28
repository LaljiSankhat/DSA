#include <bits/stdc++.h>
using namespace std;

// here we have to check that if given number is power of two or not 

// to solve this we know this if any number is power of two then only one bit is one in there binary representation 
// so if we AND with n - 1 value and if its become 0 then its power of two

bool powerOfTwo(int n){
    if(n == 0 || n == INT_MIN) return false;
    if((n & (n - 1)) == 0) return true;
    return false;
}

int main(){
    cout << powerOfTwo(5) << endl;
    cout << powerOfTwo(8) << endl;
    cout << "hello";
    return 0;
}