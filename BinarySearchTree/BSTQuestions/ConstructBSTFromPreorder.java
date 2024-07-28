package BSTQuestions;

public class ConstructBSTFromPreorder {
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
    public static Node insertIntoBST(Node root,int val){
        if(root == null){
            root = new Node(val);
            return root;
        }
        if(root.val > val){ // go left
            if(root.left == null) root.left = new Node(val);
            else insertIntoBST(root.left,val);
        }
        else{ // go right
            if(root.right == null) root.right = new Node(val);
            else insertIntoBST(root.right,val);
        }
        return root;
    }

    public static Node constructBST(int[] pre){
        Node root = new Node(pre[0]);
        for(int i = 1; i < pre.length; i++){
            root = insertIntoBST(root,pre[i]);
        }
        return root;
    }

    public static void main(String[] args) {
        int[] pre = {8,5,1,7,10,12};
        Node root = constructBST(pre);
        int level = height(root) + 1;
        for(int i = 0; i <= level; i++){
            nThLevel(root,i);
            System.out.println();
        }
//        19:30
    }
}
