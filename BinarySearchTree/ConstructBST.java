import java.util.LinkedList;
import java.util.Queue;

public class ConstructBST {
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
    public static Node constructBST(String[] arr){
        int n = arr.length;
        Queue<Node> q = new LinkedList<>();
        Node first = new Node(Integer.parseInt(arr[0]));
        q.add(first);
        for(int i = 1; i < n-1; i = i +2){
            Node temp = q.poll();
            if(!arr[i].equals("")){
                Node current = new Node(Integer.parseInt(arr[i]));
                temp.left = current;
                q.add(current);
            }
            if(!arr[i+1].equals("")){
                Node current = new Node(Integer.parseInt(arr[i+1]));
                temp.right = current;
                q.add(current);
            }
        }
        return first;
    }
    public static void preorderBST(Node root){
        if(root == null) return;
        System.out.print(root.val+" ");
        preorderBST(root.left);
        preorderBST(root.right);
    }
    public static void inorderBST(Node root){
        if(root == null) return;
        inorderBST(root.left);
        System.out.print(root.val+" ");
        inorderBST(root.right);
    }
    public static void postorderBST(Node root){
        if(root == null) return;
        postorderBST(root.left);
        postorderBST(root.right);
        System.out.print(root.val+" ");
    }
    public static void main(String[] args) {
        String[] arr = {"10","5","15","2","8","12","17"};
        Node root = constructBST(arr);
        int level = height(root) + 1;
        for(int i = 0; i <= level; i++){
            nThLevel(root,i);
            System.out.println();
        }
        preorderBST(root);
        System.out.println();
        inorderBST(root); // inorder is always sorted
        System.out.println();
        postorderBST(root);
    }
}
