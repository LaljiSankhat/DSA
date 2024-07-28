// Find middle Node given that in 1 traversal
public class q5 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static Node findMiddleNode(Node head){
        Node slow,fast;
        slow = fast = head;
        while(fast != null && fast.next != null){ // this is or right side middle for left side middle ->use fast.next.next != null
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
    // for left side middle
    static Node findMiddleNode1(Node head){
        Node slow,fast;
        slow = fast = head;
        while(fast != null && fast.next.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
    public static void main(String[] args) {
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        Node temp = findMiddleNode(a);
        Node temp1 = findMiddleNode1(a);
        System.out.println(temp.data);
        System.out.println(temp1.data);
    }
}
