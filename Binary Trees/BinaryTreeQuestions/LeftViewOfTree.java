package BinaryTreeQuestions;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class LeftViewOfTree {

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
    public static void helper(Node root, List<Integer> ans, int level){
        if(root == null) return;
        ans.set(level-1,root.val);
        helper(root.right,ans,level+1);
        helper(root.left,ans,level+1);
    }
    public static void helperRight(Node root, List<Integer> ans, int level){
        if(root == null) return;
        ans.set(level-1,root.val);
        helperRight(root.left,ans,level+1);
        helperRight(root.right,ans,level+1);
    }
    public static List<Integer> rightSideView(Node root){
        int level = height(root) + 1;
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        for(int i = 0; i < level; i++){
            ans.add(0);
        }
        helperRight(root,ans,1);
        return ans;
    }
    public static List<Integer> leftSideView(Node root){
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
        System.out.println(leftSideView(root));
        System.out.println(rightSideView(root));

        HashMap<Integer, Integer> mp = new HashMap<>();

        for(var i : mp.entrySet()){
            i.k
        }


    }
}
