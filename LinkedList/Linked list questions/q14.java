// Twin sum problem always in even ll
//ex. like 1 2 3 43 5 6  here 1 and 6 are twins, 2 & 5, 3 & 43, are twins

public class q14 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
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
    public static int maxTwinSum(Node head){
        int sum = 0;
        Node slow = head;
        Node fast = head;
        while(fast.next != null && fast.next.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        Node temp = reverse(slow.next);
        Node p1 = head;
        Node p2 = temp;
        while(p2 != null){
            int s = (p1.data + p2.data);
            if(s > sum) sum = s;
            p1 = p1.next;
            p2 = p2.next;
        }
        return sum;
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
        int z = maxTwinSum(a);
        System.out.println("Maximum twin sum is " + z);
    }
}
