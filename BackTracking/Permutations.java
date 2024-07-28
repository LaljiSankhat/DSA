
/*
 * Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 * 
 * Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
 */

import java.util.ArrayList;
import java.util.List;

public class Permutations {
    static void printP(String str, String t, List<String> l) {
        if (str.equals("")) {
            l.add(t);
            return;
        }
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            String left = str.substring(0, i);
            String right = str.substring(i + 1);
            String rem = left + right;
            printP(rem, t + ch, l);
        }

    }

    // backtracking solution
    static void permutations(int[] nums, List<Integer> l, List<List<Integer>> ans, boolean[] isVisited) {
        if (isVisited[nums.length - 1] == true)
            return;
        for (int i = 0; i < nums.length; i++) {
            if (isVisited[i] == true)
                return;
            l.add(nums[i]);
            isVisited[i] = true;
            permutations(nums, l, ans, isVisited);
            ans.add(l);
            l.remove(i);
            isVisited[i] = false;
        }
    }

    private static void helper(int[] nums, List<Integer> ds, boolean[] isValid, List<List<Integer>> ans) {
        if (ds.size() == nums.length) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < ds.size(); i++) {
                list.add(ds.get(i));
            }
            ans.add(list);
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (isValid[i] == false) {
                ds.add(nums[i]);
                isValid[i] = true;
                helper(nums, ds, isValid, ans);
                // backtracking
                ds.remove(ds.size() - 1);
                isValid[i] = false;
            }
        }
    }
    // method 1

    public static List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        boolean[] isValid = new boolean[nums.length];
        helper(nums, ds, isValid, ans);
        return ans;
    }

    // method 2
    private static void helper2(int[] nums, int idx, List<List<Integer>> ans) {
        int n = nums.length;
        if (idx == n) {
            List<Integer> ll = new ArrayList<>();
            for (int i = 0; i < nums.length; i++) {
                ll.add(nums[i]);                
            }
            ans.add(ll);
            return;
        }
        for (int i = idx; i < n; i++) {
            swap(i, idx, nums);
            helper2(nums, idx + 1, ans);

            // backtracking
            swap(i, idx, nums);
        }
    }

    private static void swap(int i, int idx, int[] nums) {
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
    }

    public static List<List<Integer>> permute2(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        helper2(nums, 0, ans);
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3 };
        // String s = "abc";
        // List<String> l = new ArrayList<>();
        // printP(s, "",l);
        // System.out.println(l);
        List<List<Integer>> ans = permute2(nums);
        // boolean[] isValid = new boolean[nums.length];
        // permutations(nums, null, ans, isVisited);

        System.out.println(ans);
    }
}
