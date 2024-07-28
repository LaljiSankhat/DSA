import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class PreInPost {
    
    static void pip(int n){
        if(n == 0) return;
        System.out.println("pre "+n); // pre
        pip(n-1);
        System.out.println("in "+n); // in
        pip(n-1);
        System.out.println( "post "+n); // post
    }

    static void preorder(Node root){
        if(root == null) return;
        // preorder root left right calls
        System.out.print(root.val+" ");
        preorder(root.left);
        preorder(root.right);
    }

    static void inorder(Node root){
        if(root == null) return;
        // preorder left root right calls
        inorder(root.left);
        System.out.print(root.val+" ");
        inorder(root.right);
    }

    static void postorder(Node root){
        if(root == null) return;
        // preorder left right root calls
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.val+" ");
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

    static void bfs(Node root){ // breadth first search iterative approach to traverse in tree
        Queue<Node> q = new LinkedList<>();
        if(root != null) q.add(root);
        while(q.size() > 0){
            Node temp = q.peek();
            if(temp.left != null) q.add(temp.left);
            if(temp.right != null) q.add(temp.right);
            System.out.print(temp.val+" ");
            q.remove();
        }
    }
    static void dfsInorder(Node root){ // depth first search  use of stack as same as inorder
        Stack<Node> st = new Stack<>();
        if(root != null) st.push(root);
        while(st.size() > 0){
            Node temp = st.peek();
            if(temp.left != null) {
                st.push(temp.left);
                temp.left = null;
            }
            else {
                st.pop();
                System.out.print(temp.val+" ");
                if(temp.right != null) st.push(temp.right);
            }

        }
    }
    static void dfsPreorder(Node root){ // depth first search  use of stack as same as inorder
        Stack<Node> s = new Stack<>();
        if(root != null) {
            System.out.print(root.val+" ");
            s.push(root);
        }
        while(s.size() > 0){
            Node temp = s.peek();
            if(temp.left != null) {
                System.out.print(temp.left.val+" ");
                s.push(temp.left);
                temp.left = null;
            }
            else {
                s.pop();
                if(temp.right != null) {
                    System.out.print(temp.right.val+" ");
                    s.push(temp.right);
                }
            }

        }
    }
    static void dfsPostorder(Node root){ // depth first search  use of stack as same as inorder
        Stack<Node> st = new Stack<>();
        if(root != null) st.push(root);
        while(st.size() > 0){
            Node temp = st.peek();
            if(temp.left != null) {
                st.push(temp.left);
                temp.left = null;
            }
            else {
                if(temp.right != null) {
                    st.push(temp.right);
                    temp.right = null;
                }else{
                    st.pop();
                    System.out.print(temp.val+" ");
                }
            }

        }
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
        preorder(root);
        System.out.println();
        inorder(root);
        System.out.println();
        postorder(root);
        System.out.println();
//        nThLevel(root,1);
//        System.out.println();
//        nThLevel(root,2);
//        System.out.println();
//        nThLevel(root,3);
        int level = height(root) + 1;
        for(int i = 0; i <= level; i++){
            nThLevel(root,i);
            System.out.println();
        }
//        bfs(root);
        // 2 : 42 : 00
        System.out.println();
//        dfs(root);
        // 3 : 11 : 00
        // hw = pre and post using stacks
//        System.out.println();
//        dfsPreorder(root); // after this all right connection is broken
//        System.out.println();
//        dfsPostorder(root); // after this all right left connection are broken  so run and comment this
        nThLevel(root,3);

    }
}
