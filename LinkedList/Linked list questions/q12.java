// Reverse a linked list


public class q12 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static void display(Node head){
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
    }
    // Using Recursion
    public static Node reverseLL(Node head){
//        Node temp1 = head;
        if(head.next == null) return head;
        Node newHead = reverseLL(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }

    // Iterative approach
    public static Node reverseLLByIterative(Node head){
        Node pre = null;
        Node current = head;
        Node n = null;
        while(current != null){
            n  = current.next;
            current.next = pre;
            pre = current;
            current = n;
        }
        return pre;
    }
    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(2);
        Node d = new Node(3);
        Node e = new Node(4);
        Node g = new Node(5);
        Node f = new Node(5);
        Node h = new Node(10);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = g;
        g.next = h;
//        Node temp = reverseLL(a);
//        display(temp);
//        System.out.println();
        Node l = reverseLLByIterative(a);
        display(l);
    }
}
