// Remove duplicates from sorted linked lists

public class q11 {
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
    static Node removeDuplicates(Node head){
        Node temp1 = head;
        Node temp2 = head.next;
        while(temp2 != null){
            if(temp2.data == temp1.data){
                temp1.next = temp2.next;
                temp2 = temp2.next;
                continue;
            }
            temp1 = temp2;
            temp2 = temp2.next;
        }
        return head;
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
        Node temp = removeDuplicates(a);
        display(temp);
    }
}
