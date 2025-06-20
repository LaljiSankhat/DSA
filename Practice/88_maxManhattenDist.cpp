#include <bits/stdc++.h>
using namespace std;


// leetcode 3443. Maximum Manhattan Distance After K Changes

int maxDistance(string s, int k) {
    int ans = 0;
    for(char hor : {'E', 'W'}){
        for(char ver : {'N', 'S'}){
            int remainingK = k, netX = 0, netY = 0;
            for(char ch : s){
                if(ch == hor && remainingK){
                    ch = (ch == 'W') ? 'E' : 'W';
                    remainingK--;
                } else if(ch == ver && remainingK){
                    ch = (ch == 'N') ? 'S' : 'N';
                    remainingK--;
                }
                netX += (ch == 'E');
                netX -= (ch == 'W');
                netY += (ch == 'N');
                netY -= (ch == 'S');
                ans = max(ans, abs(netX) + abs(netY));
            }
        }
    }
    return ans;
}


int main(){
    string s = "NWSE";
    int k = 1;
    cout << maxDistance(s, k) << endl;
    return 0;
}