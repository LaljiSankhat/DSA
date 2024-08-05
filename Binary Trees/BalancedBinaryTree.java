
/*
balance binary tree if difference of heights of right and left subtree atmost 1
 */


public class BalancedBinaryTree {
    private static class  Node {
        int data;
        Node left;
        Node right;
        public Node(int data){
            this.data = data;
        }
    }
    public static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public static boolean isBalanced(Node root){
//        if(root == null || (root.left == null && root.right == null)) return false;
//        int leftHeight = 0;
//        int rightHeight = 0;
//        if(root.left != null) leftHeight = height(root.left);
//        if(root.right != null) rightHeight = height(root.right);
        if(root == null) return true;
        int leftHeight = height(root.left);
        if(root.left != null) leftHeight++;
        int rightHeight = height(root.right);
        if(root.right != null) rightHeight++;
        int d = leftHeight - rightHeight;
        if(d < 0) d = -d;
        if(d > 1) return false;
        return (isBalanced(root.left) && isBalanced(root.right));
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
        System.out.println(isBalanced(root));
    }
}
