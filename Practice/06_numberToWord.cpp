#include <bits/stdc++.h>
using namespace std;


/*
    273. Integer to English Words
Convert a non-negative integer num to its English words representation. 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1
*/

string findForThreeDigit(int i, string s, string singleDigit[],string doubleDigit[], string tens[]){
    string ans = "";
    if(s[i] != '0'){
        ans = singleDigit[s[i] - '0'];
        ans = ans + "Hundred ";
    }
    if(s[i + 1] != '0'){
        if(s[i + 1] == '1'){
            ans = ans + doubleDigit[s[i + 2] - '0'];
            return ans;
        } else {
            ans = ans + tens[s[i + 1] - '0'];
        }
    }
    if(s[i + 2] != '0'){
        ans += singleDigit[s[i + 2] - '0'];
    }
    return ans;
}



string numberToWord(int num){
    string s = to_string(num);
    string singleDigit[] = {"Zero ","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
    string doubleDigit[] = {"Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    string zeros[] = {"", "", "Hundred ", "Thousand ", "", "", "Million ", "", "", "Billion "};
    string tens[] = {"", "", "Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};

    string ans = "";
    int n = s.size();

    // for(int i = n - 1; i >= 0; i = i - 3){
    //     string temp = "";
    //     if(i - 2 >= 0){
    //         temp =  findForThreeDigit(i - 2, s, singleDigit, doubleDigit, tens);
    //         if(temp == "") continue;
    //         int noOfZeroAfterChar = n - (i) - 1;
    //         if(noOfZeroAfterChar >= 3) temp = temp + zeros[noOfZeroAfterChar];
    //         ans = temp + ans; 
    //     } else if(i - 1 >= 0){
    //         if(s[i - 1] == '1'){
    //             temp = doubleDigit[s[i - 1] - '0'];
    //             int noOfZeroAfterChar = n - (i) - 1;
    //             temp = temp + zeros[noOfZeroAfterChar];
    //             return temp + ans;
    //         } else {
    //             temp = temp + tens[s[i - 1] - '0'];
    //             if(s[i] != '0'){
    //                 temp = temp + singleDigit[s[i] - '0'];
    //             }
    //             int noOfZeroAfterChar = n - (i) - 1;
    //             temp = temp + zeros[noOfZeroAfterChar];
    //             return temp + ans;
    //         }
    //     } else {
    //         temp = temp + singleDigit[s[i] - '0'];
    //         int noOfZeroAfterChar = n - (i) - 1;
    //         temp = temp + zeros[noOfZeroAfterChar];
    //         return temp + ans;
    //     }
    // }


    for(int i = n - 1; i >= 0; i = i - 3){
        string temp = "";
        if(i - 2 >= 0){
            temp =  findForThreeDigit(i - 2, s, singleDigit, doubleDigit, tens);
            if(temp == "") continue;
        } else if(i - 1 >= 0){
            if(s[i - 1] == '1'){
                temp = doubleDigit[s[i] - '0'];
            } else {
                temp = temp + tens[s[i - 1] - '0'];
                if(s[i] != '0'){
                    temp = temp + singleDigit[s[i] - '0'];
                }
            }
        } else {
            temp = temp + singleDigit[s[i] - '0'];
        }

        int noOfZeroAfterChar = n - (i) - 1;
        if(noOfZeroAfterChar >= 3) temp = temp + zeros[noOfZeroAfterChar];
        ans = temp + ans; 
    }
    return ans;
}


int main(){
    int num = 12345;
    string s = "123";
    // cout << findForThreeDigit(0, s)
    cout << numberToWord(num);
    return 0;
}