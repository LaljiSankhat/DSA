package BinaryTreeQuestions;

import java.util.ArrayList;
import java.util.List;

/*
 it is iterative traversal of tree  space complexity = O(1)
 */

/*
    class Solution {
        public List<Integer> inorderTraversal(TreeNode root) {
            TreeNode current = root;
            List<Integer> arr = new ArrayList<>();
            while(current != null){
                if(current.left != null){
                    TreeNode pred = current.left;
                    while(pred.right != null && pred.right != current) pred = pred.right;
                    if(pred.right == null){
                        pred.right = current;
                        current = current.left;
                    }
                    if(pred.right == current){
                        pred.right = null;
                        arr.add(current.val);
                        current = current.right;
                    }
                }
                else{
                    arr.add(current.val);
                    current = current.right;
                }
            }
            return arr;
        }   
    }

 */


public class MorrisTraversalForFlatten {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static Node morrisTraversal(Node root){
        Node current = root;
        while(current != null){
            if(current.left != null){
                Node predecessor = current.left;
                while(predecessor.right != null) predecessor = predecessor.right;
                predecessor.right = current.right;
                current.right = current.left;
                current.left = null;
            }
            current = current.right;
        }
        return root;
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
        Node temp = morrisTraversal(root);
        while(temp != null){
            System.out.print(temp.val+" ");
            temp = temp.right;
        }
//        49 : 30
    }
}
