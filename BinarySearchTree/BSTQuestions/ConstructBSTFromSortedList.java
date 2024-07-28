package BSTQuestions;

import java.util.ArrayList;
import java.util.List;

public class ConstructBSTFromSortedList {
    public static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val = val;
        }
    }
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    public static TreeNode sortedListToBST(Node head){
        Node temp = head;
        int n = 0;
        while(temp != null){
            n++;
            temp = temp.next;
        }
        temp = head;
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = temp.data;
            temp = temp.next;
        }
        return constructBST(arr,0,n-1);
    }
    public static TreeNode constructBST(int[] arr, int l, int h){
        if(l > h) return null;
        int mid = l + (h - l)/2;
        TreeNode root = new TreeNode(arr[mid]);
        root.left = constructBST(arr,l,mid - 1);
        root.right = constructBST(arr,mid + 1,h);
        return root;
    }
    public static void preorderBST(TreeNode root){
        if(root == null) return;
        System.out.print(root.val+" ");
        preorderBST(root.left);
        preorderBST(root.right);
    }

    public static void main(String[] args) {
        Node a = new Node(-10);
        Node b = new Node(-3);
        Node c = new Node(0);
        Node d = new Node(5);
        Node e = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = null;
        TreeNode temp = sortedListToBST(a);
        preorderBST(temp);
    }
}

/*
 // leetCode

 class Solution {
    public TreeNode sortedListToBST(ListNode head){
        ListNode temp = head;
        int n = 0;
        while(temp != null){
            n++;
            temp = temp.next;
        }
        temp = head;
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = temp.val;
            temp = temp.next;
        }
        return constructBST(arr,0,n-1);

    }
    public TreeNode constructBST(int[] arr, int l, int h){
        if(l > h) return null;
        int mid = l + (h - l)/2;
        TreeNode root = new TreeNode(arr[mid]);
        root.left = constructBST(arr,l,mid - 1);
        root.right = constructBST(arr,mid + 1,h);
        return root;
    }
}
 */
