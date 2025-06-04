

// leetocode 987. Vertical Order Traversal of a Binary Tree

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class VerticlaOrderTraversal {

    private class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }

    private static int findLeftMost(TreeNode root){
        int ans = 0;
        int m = 0;

        while(root.left != null || root.right != null){
            while(root.left != null) {
                root = root.left;
                ans--;
                m = Math.min(m, ans);
            }
            if(root.right != null) {
                root = root.right;
                ans++;
            }
            
        }

        return m;
    }

    private static int findRightMost(TreeNode root){
        int ans = 0;
        int m = 0;

        while(root.left != null || root.right != null){
            while(root.right != null) {
                root = root.right;
                ans++;
                m = Math.max(m, ans);
            }
            if(root.left != null) {
                root = root.left;
                ans--;
            }
            
        }

        return m;
    }

    public static void preorder(TreeNode root, int y, List<List<Integer>> ans){
        if(root == null) return;
        if(root.left == null && root.right == null){
            ans.get(y).add(root.val);
            return;
        }

        ans.get(y).add(root.val);
        preorder(root.left, y - 1, ans);
        preorder(root.right, y + 1, ans);
    }

    // this will not work in leetcode
    public static List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();

        int left = findLeftMost(root);
        int right = findRightMost(root);

        int n = right - left + 1;

        for (int i = 0; i < n; i++) {
            ans.add(new ArrayList<>());
        }

        preorder(root, n, ans);

        for (List<Integer> innerList : ans) {
            Collections.sort(innerList);
        }

        return ans;    
    }
    public static void main(String[] args) {
        
    }    
}



/* 
    
    class Solution {
        class Pair {
            int[] first;
            TreeNode second;

            Pair(int[] first, TreeNode second) {
                this.first = first;
                this.second = second;
            }
        }

        public List<List<Integer>> verticalTraversal(TreeNode root) {
            List<List<Integer>> ans = new ArrayList<>();
            if (root == null)
                return ans;

            Queue<Pair> q = new ArrayDeque<>();  //
            q.offer(new Pair(new int[] {0, 0}, root));

            Map<Integer, List<int[]>> map = new TreeMap<>();

            while (!q.isEmpty()) {
                int n = q.size();
                int dis = q.peek().first[0];
                int level = q.peek().first[1];
                TreeNode node = q.peek().second;
                q.poll();

                map.computeIfAbsent(dis, k -> new ArrayList<>()).add(new int[] {level, node.val});

                if (node.left != null)
                    q.offer(new Pair(new int[] {dis - 1, level + 1}, node.left));
                if (node.right != null)
                    q.offer(new Pair(new int[] {dis + 1, level + 1}, node.right));
            }

            for (Map.Entry<Integer, List<int[]>> em : map.entrySet()) {

                List<int[]> dummy = em.getValue();
                List<Integer> temp = new ArrayList<>();

                Collections.sort(dummy, (a, b) -> {
                    if (a[0] == b[0])
                        return a[1] - b[1];
                    return a[0] - b[0];
                });

                for (int[] ele : dummy)
                    temp.add(ele[1]);

                ans.add(temp);
            }

            return ans;
        }
    }
 */
