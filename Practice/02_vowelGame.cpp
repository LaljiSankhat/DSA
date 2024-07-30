#include <bits/stdc++.h>
using namespace std;


bool doesAliceWin(string s) {
    int n = s.size();
    vector<int> vowelPref(n, 0);
    if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') vowelPref[0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            vowelPref[i] = 1 + vowelPref[i - 1];
        } else{
            vowelPref[i] = vowelPref[i - 1];
        }
        cout << vowelPref[i] << " ";
    }

    for(int i = 0; i < n; i++){
        if((vowelPref[i] % 2 == 1) && (vowelPref[n - 1] - vowelPref[i] % 2 != 0)) return true;
    }
    cout << endl;

    return false;

}

int main(){
    string s = "leetcode";
    cout << "hello" << endl;
    cout << doesAliceWin(s) << endl;
    return 0;
}