package BSTQuestions;


import java.util.ArrayList;
import java.util.List;

/* // leetcode 99
 You are given the root of a binary search tree (BST),
  where the values of exactly two nodes of the tree were swapped by mistake.
  Recover the tree without changing its structure.

  Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 */
public class RecoverBST {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    static Node prev = null;
    static Node first = null;
    static Node second = null;
//    public static void morrisTraversal(Node root,List<Node> a){
//        Node current = root;
//        while(current != null){
//            if(current.left != null){
//                Node pred = current.left;
//                while(pred.right != null && pred.right != current) pred = pred.right;
//                if(pred.right == null){
//                    pred.right = current;
//                    current = current.left;
//                }
//                if(pred.right == current){
//                    pred.right = null;
////                    System.out.print(current.val+" ");
//                    if(c == null || p == null) c = current;
//                    else{
//                        pp = p;
//                        p = c;
//                        c = current;
//                        if(pp == null && p.val >) a.add(p);
//
//                    }
//                    current = current.right;
//                }
//            }
//            else{
//                System.out.print(current.val+" ");
//                current = current.right;
//            }
//        }
//    }
    public static void inorder(Node root){
        if(root==null)
            return ;
        inorder(root.left);
        if(prev!=null&&root.val<prev.val){
            if(first==null)
                first=prev;
            second=root;
        }
        prev=root;
        inorder(root.right);
    }
    public static void recoverBST(Node root){
        inorder(root);
        int temp=first.val;
        first.val=second.val;
        second.val=temp;
    }
    public static void main(String[] args) {

    }
}
