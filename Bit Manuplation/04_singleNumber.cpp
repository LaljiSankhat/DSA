#include <bits/stdc++.h>
using namespace std;


// here we have an array we have to identify the element which is not occure twice rest of occure twice

// to solve this we know the xor of same number results in 0 so if xor all elem in array then twice occured num
// become zero and only number will stay which occure only one time

int singleNumber(vector<int> &arr){
    int n = arr.size();
    int temp = 0;
    for(int i = 0; i < n; i++){
        temp = (arr[i] xor temp);
    }
    return temp;
}

int main(){
    vector<int> arr = {1, 4, 6, 8, 1, 4, 8};
    cout << singleNumber(arr) << endl;
    return 0;
}