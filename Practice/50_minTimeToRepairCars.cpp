#include <bits/stdc++.h>
using namespace std;


// leetcode 2594. Minimum Time to Repair Cars

bool isPossibleToRepairInTime(vector<int>& ranks, int cars, long long time){
    long long carsWithTime = 0;
    for(int r : ranks){
        long long nsq = time / r;
        carsWithTime += sqrt(nsq);
    }
    return carsWithTime >= cars;
}

long long repairCars(vector<int>& ranks, int cars){
    long long l = 1, r = 1e14;

    while(l < r){
        long long mid = l + (r - l) / 2;
        if(isPossibleToRepairInTime(ranks, cars, mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}


int main(){
    vector<int> ranks = {4,2,3,1};
    int cars = 10;
    cout << repairCars(ranks, cars) << endl;
    return 0;
}