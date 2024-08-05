

public class SearchInBST {
    private static class Node{
        int val;
        Node left;
        Node right;
        public Node(int val){
            this.val = val;
        }
    }
    static void nThLevel(Node root,int n){
        if(root == null) return;
        if(n == 1){
            System.out.print(root.val+" ");
            return;
        }
        // preorder root left right calls
        nThLevel(root.left,n-1);
        nThLevel(root.right,n-1);
    }
    static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }

    public static Node searchInBST(Node root,int val){
        if(root == null) return null;
        if(val > root.val) return searchInBST(root.right,val);
        else if(val < root.val) return searchInBST(root.left,val);
        return root;
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
//        int level = height(root) + 1;
//        for(int i = 0; i <= level; i++){
//            nThLevel(root,i);
//            System.out.println();
//        }
        System.out.println(searchInBST(root,1));
        System.out.println(c);
    }
}
