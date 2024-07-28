package BSTQuestions;

public class ValidBST {
    static Node temp = null;
    static boolean flag = true;
    public static void inorder(Node root){
        if(root == null) return;
        inorder(root.left);
        // work
        if(temp == null) temp = root;
        else{
            if(root.val < temp.val) flag = false;
            else {
                temp = root;
            }
        }
        inorder(root.right);
    }
    public static boolean isValid(Node root){
        inorder(root);
        return flag;
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
        System.out.println(isValid(root));
    }
}
