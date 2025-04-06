public class LowestCommonAncestorOfLeaf {
    private static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        public TreeNode(int x) {
            val = x;
            this.left = null;
            this.right = null;
        }
    }
    // static int d = 0;
    // static TreeNode res = null;

    // public static void findNode(TreeNode root, TreeNode parent, int depth){
    //     if(root.left == null && root.right == null) {
    //         if(d < depth){
    //             d = depth;
    //             res = parent;
    //         }
    //         return;
    //     }

    //     if(root.left != null) {
    //         findNode(root.left, root, depth + 1);
    //     }
    //     if(root.right != null) {
    //         findNode(root.right, root, depth + 1);
    //     }
    //     return;
    // }

    private static class Pair {
        int depth;
        TreeNode node;
        Pair(int depth, TreeNode node) {
            this.depth = depth;
            this.node = node;
        }
    }

    private static Pair helper(TreeNode root){
        if (root == null) return new Pair(0, null);

        Pair left = helper(root.left);  
        Pair right = helper(root.right);

        if(left.depth == right.depth) {
            return new Pair(left.depth + 1, root);
        } else if(left.depth > right.depth) {
            return new Pair(left.depth + 1, left.node);
        } else {
            return new Pair(right.depth + 1, right.node);
        }

        // return new Pair(0, null);
    }
    public static TreeNode lcaDeepestLeaves(TreeNode root) {
        // d = 0;
        // res = null;
        // if(root.left != null) findNode(root.left, root, d);
        // if(root.right != null) findNode(root.right, root, d);
        // return res;

        return helper(root).node;
    }
    public static void main(String[] args) {
        
    }
}