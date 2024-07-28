public class SizeMaxSumHeight {
    static int size = 0;
    static int size(Node root){
        if(root == null) return 0;
        return 1 + size(root.left) + size(root.right);
    }
    static int height(Node root){ // level vise
        if(root == null) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    static int heightByEdges(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(heightByEdges(root.left),heightByEdges(root.right));
    }
    static int sum(Node root){
        if(root == null) return 0;
        return root.val + sum(root.left) + sum(root.right);
    }
    static int maxValue(Node root){
        if(root == null) return Integer.MIN_VALUE;
        return Math.max(maxValue(root.left),Math.max(maxValue(root.right),root.val));
//        int a = root.val;  //  method 2 (Simplified)
//        int b = maxValue(root.left);
//        int c = maxValue(root.right);
//        return Math.max(a,Math.max(b,c));
    }
    static int minValue(Node root){
        if(root == null) return Integer.MAX_VALUE;
        return Math.min(minValue(root.left),Math.min(minValue(root.right),root.val));
//        int a = root.val;  //  method 2 (Simplified)
//        int b = maxValue(root.left);
//        int c = maxValue(root.right);
//        return Math.max(a,Math.max(b,c));
    }
    static  int product(Node root){
        if(root == null) return 1;
        return root.val * product(root.left) * product(root.right);
    }
    static void preorder(Node root){
        if(root == null) return;
//        System.out.print(root.val+" ");
        size++;
        preorder(root.left);
        preorder(root.right);
    }
    public static void main(String[] args) {
        Node root = new Node(1);
        Node a = new Node(7);
        Node b = new Node(4);
        root.right = a;
        root.left = b;
        Node c = new Node(2);
        Node d = new Node(5);
        b.left = c;
        b.right = d;
        Node e = new Node(8);
        a.right = e;
        Node f = new Node(9);
        e.left = f;
        preorder(root);
        System.out.println(size);
        System.out.println(size(root));
        System.out.println(sum(root));
        System.out.println(maxValue(root));
        System.out.println(height(root));
        System.out.println(heightByEdges(root));
        System.out.println(minValue(root));
        System.out.println(product(root));
    }
}
