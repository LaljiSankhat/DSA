#include <bits/stdc++.h>
using namespace std;


// leetcode 1061. Lexicographically Smallest Equivalent String


// this will not work 
string solve(string s1, string s2, string baseStr){
    int n = s1.size();

    vector<char> hash(26);
    for(int i = 0; i < 26; i++){
        hash[i] = (char)((int)'a' + i);
    }

    for(int i = 0; i < 26; i++){
        cout << hash[i] << " ";
    }

    for(int i = 0; i < n; i++){
        char m = min(s1[i], s2[i]);
        char m2 = min(hash[s1[i] - 'a'], hash[s2[i] - 'a']);
        hash[s1[i] - 'a'] = min(m, m2);
        hash[s2[i] - 'a'] = min(m, m2);
    }
    cout << "" << endl;
    for(int i = 0; i < 26; i++){
        cout << hash[i] << " ";
    }
    
    string ans = "";
    for(int i = 0; i < baseStr.size(); i++){
        ans += hash[baseStr[i] - 'a'];
    }

    return ans;
}

// solution 

int find(int x, vector<int>& parent) {
    if (parent[x] != x)
        parent[x] = find(parent[x], parent);
    return parent[x];
}

void unite(int x, int y, vector<int>& parent) {
    int px = find(x, parent);
    int py = find(y, parent);
    if (px == py) return;
    if (px < py) parent[py] = px;
    else parent[px] = py;
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    vector<int> parent(26);
    for (int i = 0; i < 26; ++i) parent[i] = i;

    for (int i = 0; i < s1.size(); ++i) {
        int a = s1[i] - 'a';
        int b = s2[i] - 'a';
        unite(a, b, parent);
    }

    string ans;
    for (char c : baseStr) {
        ans += (char)(find(c - 'a', parent) + 'a');
    }

    return ans;
}




int main(){
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout << solve(s1, s2, baseStr) << endl;
    return 0;
}