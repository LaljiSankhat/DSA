

// leetcode 968. Binary Tree Cameras


public class BinaryTreeCameras{
    private static class  TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
        
    }

    static int count = 0;

    public static int dfs(TreeNode node){
        if (node == null) return 2; // Null nodes are considered covered

        int left = dfs(node.left);
        int right = dfs(node.right);

        if (left == 0 || right == 0) {
            count++; // Place a camera here
            return 1;
        }

        if (left == 1 || right == 1) {
            return 2; // This node is covered
        }

        return 0; // This node needs a camera
    }

    public static int minCameraCover(TreeNode root) {
        count = 0;
        if (dfs(root) == 0) {
            count++; // If root is not covered, place camera at root
        }
        return count;
    }
    public static void main(String[] args) {
        
    }
}