

// leetcode 124. Binary Tree Maximum Path Sum


public class BinaryTreeMaxPath {

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

    static int maxSum = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
     maxSum = Integer.MIN_VALUE;
      maxSumAns(root);
      return maxSum;
    }
    public int maxSumAns(TreeNode root){
       if(root == null)
        return 0;

        int leftSum = Math.max(0,maxSumAns(root.left));
        int rightSum = Math.max(0,maxSumAns(root.right));
        maxSum = Math.max(maxSum,root.val + leftSum + rightSum);

        return root.val + Math.max(leftSum,rightSum);
    }
    public static void main(String[] args) {
        
    }    
}
