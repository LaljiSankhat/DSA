// put all odd position at first ex like 2 3 45 1 6 4 23  --> 2 45 6 23 3 1 4

public class q16 {
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
    public static Node oddEvenLL(Node head){
        Node temp = head;
        Node odd = new Node(0);
        Node even = new Node(0);
        Node temp1 = odd;
        Node temp2 = even;
        int i = 1;
        while(temp != null){
            if(i % 2 == 0){
                temp2.next = temp;
                temp2 = temp;
            }else{
                temp1.next = temp;
                temp1 = temp;
            }
            temp = temp.next;
            i++;
        }
        temp1.next = even.next;
        return odd.next;
    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(2);
        Node d = new Node(3);
        Node e = new Node(4);
        Node f = new Node(5);
        Node g = new Node(5);
        Node h = new Node(10);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = g;
        g.next = h;
        Node t = oddEvenLL(a);
        display(a);
    }
}
