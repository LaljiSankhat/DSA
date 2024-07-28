
import java.util.*;
public class CombinationSum {
    // static int idx = 0;
    public static void helper(int[] nums,int target,int idx, int sum,List<Integer> a,List<List<Integer>> ans){
        if(sum == target){
            idx++;
            List<Integer> l = new ArrayList<>();
            for(int i = 0; i < a.size(); i++){
                l.add(a.get(i));
            }
            ans.add(l);
            return;
        }
        if(sum > target){
            idx++;
            return;
        }
        while(idx < nums.length){
            a.add(nums[idx]);
            sum += nums[idx];
            helper(nums,target,idx,sum,a,ans);
            a.remove(a.size() - 1);
        }
        // a.add(nums[idx]);
        // sum += nums[idx];
        // helper(nums,target,idx,sum,a,ans);
        // a.remove(a.size() - 1);
    }
    public static List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        int idx = 0;
        int sum = 0;
        List<Integer> a = new ArrayList<>();
        helper(nums,target,idx,sum,a,ans);
        return ans;
    }
    public static void main(String[] args) {
        int[] nums = {2,3};
        int target = 7;
        List<List<Integer>> l = combinationSum(nums,target);
        System.out.println(l);
    }
}

/*
 * class Solution {
    public void helper(int[] nums,int target,int idx, int sum,List<Integer> a,List<List<Integer>> ans){
        if(sum == target){
            idx++;
            List<Integer> l = new ArrayList<>();
            for(int i = 0; i < a.size(); i++){
                l.add(a.get(i));
            }
            ans.add(l);
            return;
        }
        if(sum > target){
            idx++;
            return;
        }
        while(idx < nums.length){
            a.add(nums[idx]);
            sum += nums[idx];
            helper(nums,target,idx,sum,a,ans);
            a.remove(a.size() - 1);
        }
        // a.add(nums[idx]);
        // sum += nums[idx];
        // helper(nums,target,idx,sum,a,ans);
        // a.remove(a.size() - 1);
    }
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        int idx = 0;
        int sum = 0;
        List<Integer> a = new ArrayList<>();
        helper(nums,target,idx,sum,a,ans);
        return ans;
    }
}
 */
