// separet parts of LL into odd and Even

public class q15 {
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
    public static Node separateOddEvenLL(Node head){
        Node temp = head;
        Node even = new Node(100);
        Node odd = new Node(100);
        Node temp1 = even;
        Node temp2 = odd;
        while(temp != null){
            if(temp.data % 2 == 0){
                temp1.next = temp;
                temp1 = temp;
                temp = temp.next;
            }else{
                temp2.next = temp;
                temp2 = temp;
                temp = temp.next;
            }
        }
        temp2.next = even.next;
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
        Node t = separateOddEvenLL(a);
        display(a);
    }
}
