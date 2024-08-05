package BinaryTreeQuestions;


/*
Given two integer arrays preorder and inorder where preorder is the
 preorder traversal of a binary tree and inorder is the inorder traversal of the same tree,
 construct and return the binary tree.

 Input: preorder = [3,9,20,15,7],
         inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Input: preorder = [-1],
       inorder = [-1]
Output: [-1]

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.
 */
public class ConstructBinaryTreeByPreorderInorder {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static Node helper(int[] preorder,int pl,int ph,int[] inorder,int il,int ih){
        if(pl > ph) return null;
        Node root = new Node(preorder[pl]);
        int i = il;
        while(inorder[i] != preorder[pl]) i++;
        int leftSize = i - il;
        root.left = helper(preorder,pl + 1,pl + leftSize,inorder,il,i-1);
        root.right = helper(preorder,pl + leftSize + 1,ph,inorder,i + 1,ih);
        return root;
    }
    public static Node builtTree(int[] preorder,int[] inorder){
        int n = preorder.length;
        return helper(preorder,0,n-1,inorder,0,n-1);
    }
    public static void display(Node root){
        if(root == null) return;
        System.out.print(root.val+" -> ");
        if(root.left != null) System.out.print(root.left.val+",");
        else System.out.print("null ");
        if(root.right != null) System.out.print(root.right.val+" ");
        else System.out.print("null ");
        System.out.println();
        if(root.left != null) display(root.left);
        if(root.right != null) display(root.right);
    }
    public static void main(String[] args) {
        int[] preorder = {1,2,4,5,3,6,7};
        int[] inorder = {4,2,5,1,6,3,7};
        Node t = builtTree(preorder,inorder);
        display(t);
//        23:00

    }
}
