// Palindrome of a linked list

public class q13 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }

//    using reverse function
    public static Node reverse(Node head){
        Node pre = null;
        Node current = head;
        Node n = null;
        while(current != null){
            n = current.next;
            current.next = pre;
            pre = current;
            current = n;
        }
        return pre;
    }
    public static boolean isPalindrome(Node head1,Node head2){
        while(head1 != null){
            if(head1.data != head2.data){
                return false;
            }
            head1 = head1.next;
            head2 = head2.next;
        }
        return true;
    }

    // Method 2
    public static boolean isPalindrome1(Node head){
        Node slow = head;
        Node fast = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        Node temp = reverse(slow.next);
        slow.next = temp;
        Node temp1 = head;
        while(temp != null){
            if(temp1.data != temp.data) return false;
            temp = temp.next;
            temp1 = temp1.next;
        }
        return true;
    }
    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(2);
        Node d = new Node(3);
        Node e = new Node(3);
        Node g = new Node(2);
        Node f = new Node(2);
        Node h = new Node(1);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = g;
        g.next = h;

        // By method 1
        Node temp = a;
        Node head = new Node(100);
        Node temp2 = head;
        while(temp != null){
            Node x = new Node(temp.data);
            temp2.next = x;
            temp2 = x;
            temp = temp.next;
        }
        Node t = reverse(head.next);
        System.out.println(isPalindrome(a,t));

        // By method 2
        System.out.println(isPalindrome1(a));
    }
}
