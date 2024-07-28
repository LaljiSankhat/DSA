/*

  You are given a string num consisting of digits only.
Return the largest palindromic integer (in the form of a string)
 that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.

Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation:
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.

Example 2:

Input: num = "00009"
Output: "9"
Explanation:
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.

*/


import java.util.ArrayList;
import java.util.List;

public class LargestPalindromicNumber {
    private static List<Integer> frequencyList(String num){
        List<Integer> l = new ArrayList<>();
        for(int i = 0; i < 10; i++) l.add(0);
        for(int i = 0; i < num.length(); i++) {
            int digit = num.charAt(i) - 48;
//            System.out.println(digit);
            l.set(digit,l.get(digit) + 1);
        }
        return l;
    }
    private static boolean isValid(List<Integer> frequency){
        int count = 0;
        for(int i = 0; i < frequency.size(); i++){
            if(frequency.get(i) % 2 != 0) count++;
        }
        if(count > 1) return false;
        return true;
    }
    public static String largestPalindromicNum(String num){
        List<Integer> frequency = frequencyList(num);
        String ans = "";
        if(!isValid(frequency)){
            System.out.println("Palindrome is not possible");
            return null;
        }
        for(int i = frequency.size() - 1; i >= 0; i--){
            while(frequency.get(i) > 1){
                ans += i;
                frequency.set(i,frequency.get(i) - 2);
            }
        }
        StringBuilder temp = new StringBuilder();
        temp.append(ans);
        temp.reverse();
        System.out.println(temp);

        for(int i = 0; i < frequency.size(); i++){
            if(frequency.get(i) == 1) ans += i;
        }
        return ans + temp;

    }
    public static void main(String[] args) {
        String num = "313551";
//        System.out.println(frequencyList(num));
        System.out.println(largestPalindromicNum(num));
    }
}
