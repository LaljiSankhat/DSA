package BSTQuestions;


import BinaryTreeQuestions.InvertBinaryTree;

import java.util.ArrayList;
import java.util.List;

/*
Given two binary search trees root1 and root2, return a list containing all
 the integers from both trees sorted in ascending order.

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
 */
public class AllElementsInTwoBSTInSortedOrder {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static void inorderByMorris(Node root,List<Integer> arr){
        if(root == null) return;
        Node current = root;
        while(current != null){
            if(current.left != null){ // find pred
                Node pred = current.left;
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
    }
    public static List<Integer> mergeLists(List<Integer> r1,List<Integer> r2){
        List<Integer> ans = new ArrayList<>();
        int l1 = r1.size();
        int l2 = r2.size();
        int i = 0, j = 0;
        while(i < l1 && j < l2){
            if(r1.get(i) > r2.get(j)){
                ans.add(r2.get(j++));
            }
            else{
                ans.add(r1.get(i++));
            }
        }
        while(i < l1) ans.add(r1.get(i++));
        while(j < l2) ans.add(r2.get(j++));
        return ans;
    }

    public static List<Integer> getAllElements(Node root1,Node root2){
        List<Integer> r1 = new ArrayList<>();
        List<Integer> r2 = new ArrayList<>();
        inorderByMorris(root1,r1);
        inorderByMorris(root2,r2);
        return mergeLists(r1,r2);
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        Node a = new Node(2);
        Node b = new Node(6);
        root.right = b;
        root.left = a;
        Node c = new Node(1);
        Node d = new Node(3);
        a.left = c;
        a.right = d;
        Node e = new Node(5);
        Node f = new Node(7);
        b.left = e;
        b.right = f;
        System.out.println(getAllElements(root,root));

    }
}
