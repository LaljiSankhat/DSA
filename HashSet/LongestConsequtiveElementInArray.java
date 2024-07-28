
// given an array return longest subsequence of consecutive elements
// exa :  {100,4,200,1,3,2} possible subsequence {1->2->3->4} {100} {200} longest is 4

import java.util.HashSet;

public class LongestConsequtiveElementInArray {
    static int lengthOfLongestConsecutiveSubsequence(int [] arr){
        HashSet<Integer> st = new HashSet<>();
        for(int a : arr){
            st.add(a);
        }
        int maxStreak = 0;
        for(int num : st){
            if(!st.contains(num-1)){ // num is starting point of sequence
                int currentNum = num;
                int currentStreak = 1;
                while(st.contains(currentNum + 1)){
                    currentStreak++;
                    currentNum++;
                }
                maxStreak = Math.max(currentStreak, maxStreak);
            }
        }
        return maxStreak;
    }
    public static void main(String[] args) {
        int [] arr = {100,4,200,1,3,2};
        int n = lengthOfLongestConsecutiveSubsequence(arr);
        System.out.println(n);
    }
}
