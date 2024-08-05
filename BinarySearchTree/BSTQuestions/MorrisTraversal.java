package BSTQuestions;

public class MorrisTraversal {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static void morrisTraversal(Node root){
        Node current = root;
        while(current != null){
            if(current.left != null){
                Node pred = current.left;
                while(pred.right != null && pred.right != current) pred = pred.right;
                if(pred.right == null){
                    pred.right = current;
                    current = current.left;
                }
                if(pred.right == current){
                    pred.right = null;
                    System.out.print(current.val+" ");
                    current = current.right;
                }
            }
            else{
                System.out.print(current.val+" ");
                current = current.right;
            }
        }
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
        morrisTraversal(root);
    }
}
