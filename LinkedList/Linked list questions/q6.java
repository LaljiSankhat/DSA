// Delete the middle Node


public class q6 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static Node deleteNode(Node head){
        Node slow,fast;
        slow = fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.data = slow.next.data;
        slow.next = slow.next.next;
        return head;
    }
    // for left middle
    static Node deleteNode2(Node head){
        Node slow,fast;
        slow = fast = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.data = slow.next.data;
        slow.next = slow.next.next;
        return head;
    }
    public static void main(String[] args) {
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        Node temp = deleteNode2(a);
        System.out.println(temp.next.data);
    }
}
