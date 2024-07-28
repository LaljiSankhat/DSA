/*

   The task is to find the smallest number with given sum of digits as S and number of digits as D.

   Example 1:

Input:
S = 9
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.


Example 2:

Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.

*/





public class SmallestNumber {
    public static String smallestNum(int sum, int digits){
        if(sum == 0 || (sum > 9 * digits)) return null;
        String result = "";
        sum -= 1;
        for(int i = digits; i > 0; i--){
            if(sum > 9){
                result = "9" + result;
                sum -= 9;
            }
            else {
                result = sum +""+ result;
                sum = 0;
            }
        }
        int a = (int)result.charAt(0) - 48;
        a += 1;
        return a + result.substring(1,result.length());
    }
    public static void main(String[] args) {
        int sum = 9;
        int digits = 2;
        System.out.println(smallestNum(9,2));

    }
}
