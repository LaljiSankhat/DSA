#include <bits/stdc++.h>
using namespace std;


/*
    1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c. 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are 
"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
*/

// to solve this we use methos in which we will find there is exists substr with all char ends at that char
// for that we take 3 var a, b, c (all -1) which store last we see that char
// now we travers in the string if all a, b, c are not -1 then we know there is substr exist which will contain all the 
// three char after that we find who occure befor all that will give ind 
// so will add ans += ind + 1  (we can combine all the char befor that index + 1 of made substr)

int noOfSubstringContainingAllCharacter(string s){
    vector<int> lastseen(3, -1);
    int n = s.size();

    int cnt = 0;

    for(int i = 0; i < n; i++){
        lastseen[s[i] - 'a'] = i;
        int minimum = min(lastseen[0], min(lastseen[1], lastseen[2]));
        if(minimum != -1){
            cnt += minimum + 1;
        }
    }

    return cnt;
}

int main(){
    string s = "abcabc";
    cout << noOfSubstringContainingAllCharacter(s);
    return 0;
}