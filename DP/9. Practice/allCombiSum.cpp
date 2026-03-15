#include <bits/stdc++.h>
using namespace std;

void helper(string s, int idx, int currentSum, vector<int> &result) {
    if (idx == s.size()) {
        result.push_back(currentSum);
        return;
    }

    int num = 0;
    for (int i = idx; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0'); 
        helper(s, i + 1, currentSum + num, result);
    }
}

int main() {
    string s = "125";
    vector<int> result;
    helper(s, 0, 0, result);

    cout << "All possible sums:\n";
    int res = 0;

    for (int sum : result) {
        cout << sum << " ";
        res += sum;
    }

    cout << res << endl;
    return 0;
}
