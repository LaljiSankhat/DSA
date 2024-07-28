#include <bits/stdc++.h>
using namespace std;


/*
    here we have to convert one number to onother so how many bits we have to flip to convert
*/

/*
    To solve we know this bit convertion we convert those which are different bits, to work on different bits we 
    have xor operator.
    now consider a = 5 = (0101) convert to 4 = (0100)
    if we do xor of this then we get (0001) so we need to count set bits in this number which is our answer
*/

int requiredNumberOfBitsToConvertNumber(int start, int dest){
    int temp = (start xor dest);

    int count = 0;

    while(temp != 0){
        temp = (temp & (temp - 1));
        count++;
    }

    return count;
}

int main(){
    int a = 10; 
    int b = 7;

    cout << requiredNumberOfBitsToConvertNumber(a, b) << endl;
    return 0;
}