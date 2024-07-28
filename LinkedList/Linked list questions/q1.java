// Delete a node given node as a parameter

public class q1 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static void deleteNode(Node a){
        a.data = a.next.data;
        a.next = a.next.next;
    }
    public static void main(String[] args) {
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        deleteNode(c);
        System.out.println(a.data);
        System.out.println(b.data);
        System.out.println(d.data);


    }
}
