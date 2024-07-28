#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 5;
    int b = 6;
    // now i have to swap this 
    a = a xor b; // after this a = a xor b
    b = a xor b; 
    // here b = (a xor b) xor b , sice b xor b = 0 so 
    //      b = a xor 0 
    //        = a, because xor with 0 become number itself
    a = a xor b;
    // here a = (a xor b) xor a    (because b = a )   now by manipulation 
    //      a = (b xor a) xor a 
    //        = b xor (a xor a) 
    //        = b xor 0 
    //        = b
    cout << a << " " << b;
    return 0;
}