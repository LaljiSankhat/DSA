// Split linked list into even and odd lists

public class q10 {
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
    static Node evenSplit(Node head){
        Node a = new Node(100);
        Node temp = a;
        Node temp1 = head;
        while(temp1 != null){
            if(temp1.data % 2 == 0){
                Node b = new Node(temp1.data);
                temp.next = b;
                temp = b;
            }
            temp1 = temp1.next;
        }
        return a.next;
    }
    static Node oddSplit(Node head){
        Node a = new Node(100);
        Node temp = a;
        Node temp1 = head;
        while(temp1 != null){
            if(temp1.data % 2 != 0){
                Node b = new Node(temp1.data);
                temp.next = b;
                temp = b;
            }
            temp1 = temp1.next;
        }
        return a.next;
    }

    public static void main(String[] args) {
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
        Node even = evenSplit(a);
        display(even);
        System.out.println();
        Node odd = oddSplit(a);
        display(odd);
    }
}
