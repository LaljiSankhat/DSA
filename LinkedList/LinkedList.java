
public class LinkedList {
    public static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }

    static void display(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    static void displayR(Node head) {
        if (head == null)
            return;
        System.out.print(head.data + " ");
        displayR(head.next);
    }

    static void displayReverse(Node head) {
        if (head == null)
            return;

        displayReverse(head.next);
        System.out.print(head.data + " ");
    }

    static int length(Node head) {
        int cnt = 0;
        while (head != null) {
            cnt++;
            head = head.next;
        }
        return cnt;
    }

    public static void main(String[] args) {
        // Node x = new Node();
        // System.out.println(x.data);
        Node a = new Node(3);
        Node b = new Node(5);
        Node c = new Node(6);
        Node d = new Node(7);
        Node e = new Node(9);
        a.next = b; // Linking of numbers to next elements
        b.next = c;
        c.next = d;
        d.next = e;
        // System.out.println(a.data);
        // Printing data of b using a
        // System.out.println(a.next.data);
        // System.out.println(a.next.next.data);

        // Print a LinkedList using for loop
        Node temp = a; // Node temp pointing at value of a
        for (int i = 0; i < 5; i++) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println("");
        // Generally we dont know the last node, we only know about the head node, sp
        // printing we use while loop
        temp = a;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println("");
        // by using functions
        display(a);
        System.out.println(" ");
        // Print a LinkedList using Recurtion
        displayR(a);
        System.out.println(" ");
        displayReverse(a);
        System.out.println(" ");

        // length of Linked List
        int len = length(a);
        System.out.println(len);

    }
}
