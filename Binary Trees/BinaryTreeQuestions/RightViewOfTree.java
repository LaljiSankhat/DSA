package BinaryTreeQuestions;


import java.util.ArrayList;
import java.util.List;

/*
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Input: root = [1,null,3]
Output: [1,3]
 */
public class RightViewOfTree {
    private static class Node{
        int val;
        Node right;
        Node left;
        public Node(int val){
            this.val = val;
        }
    }
    public static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public static void nThLevel(Node root, int n, List<Integer> l){
        if(root == null) return;
        if(n == 1){
            l.add(root.val);
            return;
        }
        // preorder root left right calls
        nThLevel(root.left,n-1,l);
        nThLevel(root.right,n-1,l);
    }
    public static List<List<Integer>> levelOrder(Node root){
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        int level = 1 + height(root);
        for(int i = 1; i <= level; i++){
            List<Integer> a = new ArrayList<>();
            nThLevel(root,i,a);
            ans.add(a);
        }
        return ans;
    }
    public static List<Integer> rightSideView1(Node root){
        List<Integer> result = new ArrayList<>();
        List<List<Integer>> ans = levelOrder(root);
        for(int i = 0; i < ans.size(); i++){
            List<Integer> a = ans.get(i);
            result.add(a.remove(a.size()-1));
        }
        return result;
    }

    // method 2
    public static void helper(Node root,List<Integer> ans, int level){
        if(root == null) return;
        ans.set(level-1,root.val);
        helper(root.left,ans,level+1);
        helper(root.right,ans,level+1);
    }
    public static List<Integer> rightSideView(Node root){
        int level = height(root) + 1;
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        for(int i = 0; i < level; i++){
            ans.add(0);
        }
        helper(root,ans,1);
        return ans;
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
        List<Integer> temp = rightSideView1(root);
        System.out.println(temp);
        System.out.println(levelOrder(root));
        System.out.println(rightSideView(root));
//        1 : 55 : 00

    }
}
