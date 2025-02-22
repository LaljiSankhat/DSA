import java.util.ArrayList;
import java.util.List;

public class RecoverTreeFromPreOrder{
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }

    private static int indDash = 0;

    private static TreeNode makeTree(int depth,List<Integer> arr, List<Integer> node){
        // if(indDash >= arr.size()) return;
        
        // TreeNode t = new TreeNode(node.get(indDash));
        // if(ind == 1 || arr.get(indDash) > arr.get(ind - 1)){
        //     indDash++;           
        //     // ind = indDash;
        //     if(root.left == null){
        //         root.left = t;
        //     } else {
        //         root.right = t;
        //     }
        //     makeTree(indDash, t, arr, node); 
        // }
        if(indDash >= node.size() || arr.get(indDash) > depth) return null;

        TreeNode root = new TreeNode(node.get(indDash));
        indDash++;

        if (indDash < node.size() && arr.get(indDash) == depth + 1) {
            root.left = makeTree(depth + 1, arr, node);
        }
        if (indDash < node.size() && arr.get(indDash) == depth + 1) {
            root.right = makeTree(depth + 1, arr, node);
        }

        return root;
        
    }

    public static TreeNode recoverTree(String traversal){
        indDash = 0;
        int n = traversal.length();
        List<Integer> arr = new ArrayList<>();
        List<Integer> node = new ArrayList<>();
        int i = 0;
        while (i < n) {
            int count = 0;
            while (i < n && traversal.charAt(i) == '-') {
                count++;
                i++;
            }
            arr.add(count); // Store depth

            int st = i;
            // int end  = i;
            while(i < n && traversal.charAt(i) != '-'){
                i++;
            }
            node.add(Integer.parseInt(traversal.substring(st, i)));
        }
        // arr.add(0, -1);
        // for(int a : arr){
        //     System.out.print(a + " ");
        // }
        // System.out.println();
        // for(int a : node){
        //     System.out.print(a + " ");
        // }
        // TreeNode root = new TreeNode(node.get(0));
        TreeNode root = makeTree(0,arr, node);
        if(root == null) System.out.println("Root is Null");
        System.out.println();
        print(root);
        return root;
    }
    private static void print(TreeNode root){
        if(root == null) {
            System.out.print("Null ");
            return;
        }
        System.out.print(root.val + " ");
        print(root.left);
        print(root.right);
    }
    public static void main(String[] args) {
        String pre = "1-401--349---90--88";
        TreeNode a = recoverTree(pre);
    }
}