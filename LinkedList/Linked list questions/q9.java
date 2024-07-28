// Merge two sorted linked list without using extra space

public class q9 {
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

    static Node mergeLL(Node head1,Node head2){
        Node a = new Node(100);
        Node temp = a;
        while(head1 != null && head2 != null){
            if(head1.data <= head2.data){
                temp.next = head1;
                temp = head1;
                head1 = head1.next;
            }
            else{
                temp.next = head2;
                temp = head2;
                head2 = head2.next;
            }
        }
        if(head1 != null){
            temp.next = head1;
        }
        else{
            temp.next = head2;
        }
        return a.next;
    }
    public static void main(String[] args) {
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        Node a1 = new Node(1);
        Node b2= new Node(2);
        Node c3 = new Node(3);
        Node d4 = new Node(5);
        a1.next = b2;
        b2.next = c3;
        c3.next = d4;
        Node temp = mergeLL(a,a1);
        display(temp);
    }
}
