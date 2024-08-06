#include <bits/stdc++.h>
using namespace std;


/*
    3016. Minimum Number of Pushes to Type Word II a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.


 

Example 1:


Input: word = "abcde"
Output: 5
Explanation: The remapped keypad given in the image provides the minimum cost.
"a" -> one push on key 2
"b" -> one push on key 3
"c" -> one push on key 4
"d" -> one push on key 5
"e" -> one push on key 6
Total cost is 1 + 1 + 1 + 1 + 1 = 5.
It can be shown that no other mapping can provide a lower cost.
*/

int minimumPushes(string word) {
    int n = word.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++) freq[word[i] - 'a']++;
    
    for(int i = 0; i < 26; i++){
        cout << freq[i];
    }
    cout << "\n";
    sort(freq.begin(), freq.end(), greater<int>());
    for(int i = 0; i < 26; i++){
        cout << freq[i];
    }
    cout << "\n";

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(freq[i] == 0) break;
        cnt++;
        if(cnt <= 8) ans += freq[i];
        else if(cnt > 8 && cnt <= 16) ans += 2 * freq[i];
        else if (cnt > 16 && cnt <= 24) ans += 3 * freq[i];
        else ans += 4*freq[i];
    }

    return ans;
}


int main(){
    string word = "aabbccddeeffgghhiiiiii";
    cout << minimumPushes(word);
    return 0;
}