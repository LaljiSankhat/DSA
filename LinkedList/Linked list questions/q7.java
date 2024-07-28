// Cycle in a linked list  q7 and q8 mixed

/* Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer
is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
*/


// Using slow and fast pointers
public class q7 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static Node hasCycle(Node head){
        Node slow,fast;
        slow = head.next;
        fast = head.next.next;
        while(fast != null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast) break;
        }
        Node temp = head;
        while(temp != slow){
            slow = slow.next;
            temp = temp.next;
        }
        return slow;
    }

    // Efficient solution
    static boolean isCycle(Node head){
        Node slow,fast;
//        slow = head.next;
//        fast = head.next.next;
//        while(fast != null){
//            slow = slow.next;
//            fast = fast.next.next;
//            if(fast == slow) return true;
//        }
//        return false;

        // Leetcode
        slow = fast = head;
        if(head == null || head.next == null) return false; // if LL is null or only one element
        while(fast != null){
            slow = slow.next;
            if(fast.next == null) return false;
            fast = fast.next.next;
            if(slow == fast) return true;
        }
        return false;
    }

    public static void main(String[] args) {
//        Node a = new Node(2);
//        Node b = new Node(6);
//        Node c = new Node(7);
//        Node d = new Node(9);
//        a.next = b;
//        b.next = c;
//        c.next = d;
//        d.next = b;
//        Node temp = hasCycle(a);
//        System.out.println(temp.data);
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        Node e = new Node(1);
        Node f = new Node(3);
        Node g = new Node(5);
        Node h = new Node(10);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = g;
        g.next = h;
        h.next = d;
        Node temp = hasCycle(a);
        System.out.println(temp.data);
    }
}
