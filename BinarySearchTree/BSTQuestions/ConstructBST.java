package BSTQuestions;

public class ConstructBST {
    public static Node constructBST(int[] arr,int l,int h){
        if(l > h) return null;
        int mid = l + (h - l)/2;
        Node root = new Node(arr[mid]);
        root.left = constructBST(arr,l,mid - 1);
        root.right = constructBST(arr,mid + 1,h);
        return root;
    }
    public static void preorderBST(Node root){
        if(root == null) return;
        System.out.print(root.val+" ");
        preorderBST(root.left);
        preorderBST(root.right);
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7};
        Node root = constructBST(arr,0,arr.length-1);
        preorderBST(root);
    }
}

/*
// leetcode

class Solution {
    public TreeNode helper(int[] arr,int l,int h){
        if(l > h) return null;
        int mid = l + (h - l)/2;
        TreeNode root = new TreeNode(arr[mid]);
        root.left = helper(arr,l,mid - 1);
        root.right = helper(arr,mid + 1,h);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] arr){
        return helper(arr,0,arr.length-1);
    }
}
 */
