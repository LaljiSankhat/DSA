// Find Node at two given linked list is intersected
// example 1 3 4 5 6   and 5 4 3 4 5 6 intersected from 4 5 6 return 4
public class q4 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static Node nodeOfIntersecting(Node head1,Node head2){
        Node temp1 = head1;
        Node temp2 = head2;
        int m =0,n=0;
        while(temp1 != null){
            m++;
            temp1 = temp1.next;
        }
        while(temp2 != null){
            n++;
            temp2 = temp2.next;
        }
        System.out.println(m+" "+n);
        temp1 = head1;
        temp2 = head2;
        if(m>n){
            for(int i = 0; i< m-n;i++){
                temp1 = temp1.next;
            }
        }else{
            for(int j = 0; j< n-m;j++){
                temp2 = temp2.next;
            }
        }
        while(temp1 != temp2){
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        return temp2;
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
        Node b1 = new Node(65);
        Node c1 = new Node(3);
//        Node d1 = new Node(7);
//        Node e1 = new Node(9);
        a1.next = b1;
        b1.next = c1;
        c1.next = c;
//        d1.next = e1;
        Node t = nodeOfIntersecting(a,a1);
        System.out.println(t.data);
    }
}
