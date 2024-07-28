import java.util.LinkedList;
import java.util.Queue;

public class DeleteNode {
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
    public static void preorderBST(Node root){
        if(root == null) return;
        System.out.print(root.val+" ");
        preorderBST(root.left);
        preorderBST(root.right);
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
    public static void deleteNodeOF0Child(Node root,int target){ // also valid for leaf node
        if(root == null) return;
        if(root.val > target){ // go left
            if(root.left.val == target) {
                root.left = null;
            }
            else deleteNodeOF0Child(root.left,target);
        }
        else if(root.val < target){ // go right
            if(root.right.val == target) root.right = null;
            else deleteNodeOF0Child(root.right,target);
        }

    }
    public static void deleteNodeOF1Child(Node root,int target){ // also valid for leaf node
        if(root == null) return;
        if(root.val > target){ // go left
            if(root.left == null) return;
            if(root.left.val == target) {
                if(root.left.left == null && root.left.right == null) root.left = null;
                else if(root.left.left != null) root.left = root.left.left;
                else if(root.left.right != null) root.left = root.left.right;
            }
            else deleteNodeOF1Child(root.left,target);
        }
        else if(root.val < target){ // go right
            if(root.right == null) return;
            if(root.right.val == target) {
                if(root.right.left == null && root.right.right == null) root.right = null;
                else if(root.right.left != null) root.right = root.right.left;
                else if(root.right.right != null) root.right = root.right.right;
            }
            else deleteNodeOF1Child(root.right,target);
        }
    }
    public static void delete(Node root,int target){
        if(root == null) return;
        if(root.val > target){ // go left
            if(root.left == null) return;
            if(root.left.val == target) {
                if(root.left.left == null && root.left.right == null) root.left = null; // leaf Node
                else if(root.left.left == null || root.left.right == null){ // 1 child
                    if(root.left.left == null) root.left = root.left.right;
                    else root.left = root.left.left;
                }
                else{ // 2 child
                     Node current = root.left;
                     Node pred = current.left;
                     while(pred.right != null) pred = pred.right;
//                     pred.right = current.right;
//                     while(pred.left != null) pred = pred.left;
//                     pred.left = current.left;
//                     root.left = pred;
                    delete(root, pred.val);
                    pred.left = current.left;
                    pred.right = current.right;
                    root.left = pred;
                }
            }
            else delete(root.left,target);
        }
        else if(root.val < target){ // go right
            if(root.right == null) return;
            if(root.right.val == target) {
                if(root.right.left == null && root.right.right == null) root.right = null; // leaf Node
                else if(root.right.left == null || root.right.right == null){ // 1 child
                    if(root.right.left == null) root.right = root.right.right;
                    else root.right = root.right.left;
                }
                else{ // 2 child
                    Node current = root.right;
                    Node pred = current.left;
                    while(pred.right != null) pred = pred.right;
//                     pred.right = current.right;
//                     while(pred.left != null) pred = pred.left;
//                     pred.left = current.left;
//                     root.left = pred;
                    delete(root, pred.val);
                    pred.left = current.left;
                    pred.right = current.right;
                    root.right = pred;
                }
            }
            else delete(root.right,target);
        }
    }
    public static Node deleteNode(Node root,int target){
        Node temp = new Node(Integer.MAX_VALUE);
        temp.left = root;
        delete(temp,target);
        root = temp.left;
        return root;
    }


    public static void main(String[] args) {
        String[] arr = {"50","20","60","17","34","55","89","10","","28","","","","70","","","14"};
        Node root = constructBST(arr);
        preorderBST(root);
//        deleteNodeOF0Child(root,14);
//        deleteNodeOF1Child(root,17);
        Node newRoot = deleteNode(root,55);
        System.out.println();
        preorderBST(newRoot);

    }
}

/*
// better solution

class Solution {
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null)return null;
        if(root.left==null&&root.right==null&&root.val==key)return null;
        if(root.val==key){
            if(root.left==null)return root.right;
            if(root.right==null)return root.left;

            TreeNode temp=root.right;
            while(temp.left!=null)temp=temp.left;
            temp.left=root.left;
            root.left=null;
            return root.right;
        }
        if(root.val>key)
            root.left= deleteNode(root.left,key);
        else
            root.right= deleteNode(root.right,key);
        return root;
    }
}
 */
