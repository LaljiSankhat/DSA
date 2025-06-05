

// leetcode 222. Count Complete Tree Nodes

public class countTotalNode {

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

    private int findHeightLeft(TreeNode node) {
        int height = 0;
        while (node != null) {
            height++;
            node = node.left;
        }
        return height;
    }

    
    private int findHeightRight(TreeNode node) {
        int height = 0;
        while (node != null) {
            height++;
            node = node.right;
        }
        return height;
    }

    public int countNodes(TreeNode root) {
        if(root == null) return 0;

        int lh = findHeightLeft(root);
        // Find the height of the right subtree
        int rh = findHeightRight(root);

        // If the heights are equal, the tree
        // is a full binary tree, and we can
        // calculate the total nodes
        if (lh == rh) {
            return (1 << lh) - 1;
        }

        // If the heights are not equal,
        // recursively count nodes in the
        // left and right subtrees
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    public static void main(String[] args) {
        
    }
}
