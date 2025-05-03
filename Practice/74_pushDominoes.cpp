#include <bits/stdc++.h>
using namespace std;


// leetcode 838. Push Dominoes

// this will give TLE 
string pushDominoes(string dominoes) {
    int n = dominoes.size();
    string ans = "";

    for(int i = 0; i < n; i++){
        if(dominoes[i] == 'L' || dominoes[i] == 'R') {
            ans += dominoes[i];
            continue;
        }
        int j = i - 1;
        while(j >= 0){
            if(dominoes[j] == 'R') break;
            else if(dominoes[j] == 'L') {
                j = -1e6;
                break;
            }
            j--;
        }
        int k = i + 1;
        while(k < n){
            if(dominoes[k] == 'L') break;
            else if(dominoes[k] == 'R') {
                k = 1e6;
                break;
            }
            k++;
        }
        if(j < 0) j = -1e6;
        if(k == n) k = 1e6;
        if((j == -1e6 && k == 1e6)) {
            ans += '.';
            continue;
        }
        if(abs(j - i) < abs(k - i)) ans += 'R';
        else if(abs(j - i) > abs(k - i)) ans += 'L';
        else ans += '.';
    }

    return ans;
}


string pushDominoesOptimized(string dominoes) {
    int n = dominoes.size();
    vector<int> forces(n, 0);
    
    // Left to right pass (R forces)
    int force = 0;
    for (int i = 0; i < n; i++) {
        if (dominoes[i] == 'R') {
            force = n;
        } else if (dominoes[i] == 'L') {
            force = 0;
        } else {
            force = max(force - 1, 0);
        }
        forces[i] += force;
    }

    // Right to left pass (L forces)
    force = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (dominoes[i] == 'L') {
            force = n;
        } else if (dominoes[i] == 'R') {
            force = 0;
        } else {
            force = max(force - 1, 0);
        }
        forces[i] -= force;
    }

    // Build result
    string result;
    for (int f : forces) {
        if (f == 0) result += '.';
        else if (f > 0) result += 'R';
        else result += 'L';
    }

    return result;

}


int main(){
    string dominoes = ".L.R...LR..L..";
    cout << pushDominoes(dominoes) << endl;
    cout << pushDominoesOptimized(dominoes) << endl;
    return 0;
}