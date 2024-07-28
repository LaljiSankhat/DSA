package BinaryTreeQuestions;

/*
Given the root of a binary tree and an integer targetSum, return the number of paths
 where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards
 (i.e., traveling only from parent nodes to child nodes).

 Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 */
public class PathSumIII {
    static int count = 0;
    public static void helper(Node root,int targetSum){
        if(root == null) return;
        if(root.val == targetSum) {
            count++;
        }
        helper(root.left,targetSum- root.val);
        helper(root.right,targetSum- root.val);
    }
    public static int pathSum(Node root,int targetSum){
        if(root == null) return count;
        helper(root,targetSum);
        pathSum(root.left,targetSum);
        pathSum(root.right,targetSum);
        return count;
    }

    public static void main(String[] args) {
        Node root = new Node(1);
        Node a = new Node(2);
        Node b = new Node(3);
        root.right = b;
        root.left = a;
        Node c = new Node(4);
        Node d = new Node(5);
        a.left = c;
        a.right = d;
        Node e = new Node(6);
        Node f = new Node(7);
        b.left = e;
        b.right = f;
        System.out.println(pathSum(root,3));
    }
}

/*
path sum 3 :

class Solution {
    public int helper(TreeNode root,long targetSum){
        if(root == null) return 0;
        int count = 0;
        if((long)root.val == targetSum) count++;
        return count + (helper(root.left,targetSum- root.val) + helper(root.right,targetSum- root.val));
    }
    public int pathSum(TreeNode root,int targetSum){
        if(root == null) return 0;
        int count = helper(root,(long)targetSum);
        count += (pathSum(root.left,targetSum) + pathSum(root.right,targetSum));
        return count;
    }
}
 */

/*
 // path sum 1 :
 Given the root of a binary tree and an integer targetSum,
 return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.

 class Solution {
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        if(root.right == null && root.left == null){
            return targetSum == root.val;
        }
        boolean a = false,b = false;
        if(root.left != null) a = hasPathSum(root.left,targetSum - root.val);
        if(root.right != null) b = hasPathSum(root.right,targetSum - root.val);
        return a || b;
    }
}
 */

/*
 // path sum 2 :

 Given the root of a binary tree and an integer targetSum,
 return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
 Each path should be returned as a list of the node values, not node references.
 A root-to-leaf path is a path starting from the root and ending at any leaf node.
 A leaf is a node with no children.

 class Solution {
    public void helper(TreeNode root,List<List<Integer>> ans, List<Integer> arr,int targetSum){
        if(root == null) return;
        arr.add(root.val);
        if(root.right == null && root.left == null){
            if(targetSum == root.val){
                List<Integer> temp = new ArrayList();
                for(int i = 0; i < arr.size(); i++){
                    temp.add(arr.get(i));
                }
                ans.add(temp);
            }
            arr.remove(arr.size()-1);
            return;
        }
        helper(root.left,ans,arr,targetSum - root.val);
        helper(root.right,ans,arr,targetSum - root.val);
        arr.remove(arr.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        List<Integer> arr = new ArrayList<>();
        helper(root,ans,arr,targetSum);
        return ans;
    }
}
 */
