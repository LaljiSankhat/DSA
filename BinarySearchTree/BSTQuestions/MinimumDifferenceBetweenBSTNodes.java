package BSTQuestions;

public class MinimumDifferenceBetweenBSTNodes {
    static Node temp = new Node(0);
    static int minDiff = Integer.MAX_VALUE;
    public static void helper(Node root){
        if(root == null) return;
        helper(root.left);
//        minDiff = Math.min(minDiff,Math.abs(temp.val - root.val));
        if(temp == null) minDiff = Integer.MAX_VALUE;
        else minDiff = Math.min(minDiff,Math.abs(temp.val - root.val));
        temp = root;
        helper(root.right);
    }
    public static int minDiffInBST(Node root){
        helper(root);
        return minDiff;
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        Node a = new Node(2);
        Node b = new Node(6);
        root.right = b;
        root.left = a;
        Node c = new Node(1);
        Node d = new Node(3);
        a.left = c;
        a.right = d;
        Node e = new Node(5);
        Node f = new Node(7);
        b.left = e;
        b.right = f;
        System.out.println(minDiffInBST(root));
    }
}
