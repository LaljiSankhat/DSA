package BinaryTreeQuestions;


import java.util.LinkedList;
import java.util.Queue;

/*
return tree from given an array

ex : {1,2,3,4,5,null,6,null,7,null,null,8,null,null,null,9,null}
output
1
2 3
4 5 null 6
null 7 null null 8 null
null null 9 null
 */
public class ConstructTreeByLevelOrderTraversal {
    public static Node constructTree(String[] arr){
        Queue<Node> q = new LinkedList<>();
        int first = Integer.parseInt(arr[0]);
        Node root = new Node(first);
        q.add(root);
        for(int i = 1; i < arr.length - 1; i = i+2){
            Node current = q.poll();
            if(!arr[i].equals("")){
                int num = Integer.parseInt(arr[i]);
                Node a = new Node(num);
                current.left = a;
                q.add(a);
            }
            if(!arr[i+1].equals("")){
                int nextNum = Integer.parseInt(arr[i+1]);
                Node a = new Node(nextNum);
                current.right = a;
                q.add(a);
            }
        }
        return root;
    }
    static void nThLevel(Node root, int n){
        if(root == null) return;
        if(n == 1){
            System.out.print(root.val+" ");
            return;
        }
        // preorder root left right calls
        nThLevel(root.left,n-1);
        nThLevel(root.right,n-1);
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
    static int height(Node root){
        if(root == null || (root.left == null && root.right == null)) return 0;
        return 1 + Math.max(height(root.left),height(root.right));
    }
    public static void main(String[] args) {
        // convert string into number
//        String str = "1";
//        int a = Integer.parseInt(str);
//        System.out.println(a); // 1
//        System.out.println(a+10); //11 because 1 + 10 = 11

        String[] arr = {"1","2","3","4","5","","6","","7","","","8","","","","9",""};
        Node root = constructTree(arr);
        display(root);
        System.out.println();
        int level = height(root) + 1;
        for(int i = 0; i <= level; i++){
            nThLevel(root,i);
            System.out.println();
        }


    }
}
