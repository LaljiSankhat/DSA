package Java;

import java.util.Arrays;

public class NthStair {
    public static int climbStair(int n, int[] dp){
        if(n <= 1) return 1;
        int left = 0;
        int right = 0;
        if(dp[n - 1] != -1) left = dp[n - 1];
        else left = climbStair(n - 1, dp);
        if(dp[n - 2] != -1) right = dp[n - 2];
        else right = climbStair(n - 2, dp);
        dp[n] = left + right;
        return dp[n];
    }

    // space optimised
    public static int spaceOptimised(int n){
        int pre1 = 1;
        int pre2 = 1;
        for(int i = 2; i <= n; i++){
            int res = pre1 + pre2;
            pre2 = pre1;
            pre1 = res;
        }
        return pre1;
    }
    public static void main(String[] args) {
        int n = 44;
        int[] dp = new int[n + 1];
        Arrays.fill(dp,-1);
        System.out.println(climbStair(n,dp));
        System.out.println(spaceOptimised(n));

    }
}
