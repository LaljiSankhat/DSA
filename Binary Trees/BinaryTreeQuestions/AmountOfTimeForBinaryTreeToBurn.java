package BinaryTreeQuestions;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

// Amount Of Time For Binary Tree To be Infected
/*
You are given the root of a binary tree with unique values, and an integer start.
At minute 0, an infection starts from the node with value start.
Each minute, a node becomes infected if:
The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected, so we return 4.

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected, so we return 0.
 */
public class AmountOfTimeForBinaryTreeToBurn {
    public static Node findNode(Node root,int start){ // tree always have start node
        if(root == null) return null;
        if(root.val == start) return root;
        Node left = findNode(root.left,start);
        Node right = findNode(root.right,start);
        if(left == null) return right;
        return left;
    }
    public static void fillParents(Node root,HashMap<Node,Node> parent){
        if(root == null) return;
        if(root.left != null) parent.put(root.left,root);
        if(root.right != null) parent.put(root.right,root);
        fillParents(root.left,parent);
        fillParents(root.right,parent);
    }
    public static int amountOfTime(Node root,int start){
        Node startNode = findNode(root,start);
        HashMap<Node,Node> parent = new HashMap<>();
        fillParents(root,parent);
        // bfs
        HashMap<Node,Integer> isVisited = new HashMap<>();
        Queue<Node> q = new LinkedList<>();
        q.add(startNode);
        isVisited.put(startNode,0);
        while(q.size() > 0){
            Node temp = q.peek();
            if(temp.left != null && !isVisited.containsKey(temp.left)){
                q.add(temp.left);
                isVisited.put(temp.left,isVisited.get(temp) + 1);
            }
            if(temp.right != null && !isVisited.containsKey(temp.right)){
                q.add(temp.right);
                isVisited.put(temp.right,isVisited.get(temp) + 1);
            }
            if(parent.containsKey(temp) && !isVisited.containsKey(parent.get(temp))){
                q.add(parent.get(temp));
                isVisited.put(parent.get(temp),isVisited.get(temp) + 1);
            }
            q.remove();
        }
        int minutes = -1;
        for(var e : isVisited.entrySet()){
            minutes = Math.max(minutes,e.getValue());
        }
        return minutes;
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
        System.out.println(amountOfTime(root,3));
    }
}
