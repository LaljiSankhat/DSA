package HashMapQuetions;

import java.util.HashMap;

// given a target return a pair of indices whose sum is equals to target
// arr = {1,5,7,-1} target = 6  here 5 + 1 = 6 so return 0 1 else return -1
public class TwoSum {
    // brute force approch
    static int[] twoSumBrut(int [] arr, int target){
        int [] ans = {-1};
        for(int i = 0; i < arr.length; i++){
            for(int j = i+1; j < arr.length; j++){
                if(arr[i] + arr[j] == target){
                    // ans[0] = i;
                    // ans[1] = j;  
                    ans = new int[]{i,j};                  
                    return ans;
                }
            }
        }
        return ans;
    }

    // better approch
    static int[] twoSum(int [] arr, int target){
        int n = arr.length;
        int [] res = {-1};
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i = 0; i < n; i++){
            int partner = target - arr[i];
            if(mp.containsKey(partner)){
                res = new int[]{i,mp.get(partner)};
                return res;
            }
            mp.put(arr[i], i);
        }
        return res;
    }
    public static void main(String[] args) {
        int [] arr = {14,7,10,4,5,9,1,2};
        int target = 13;
        int [] a = twoSum(arr, target);
        for(var e : a){
            System.out.print(e+" ");
        }
    }
}
