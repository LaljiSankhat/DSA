

class linkedlist {
    public static class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
        }
    }
    Node head = null;
    Node tail = null;
    int size = 0;

    public void insertAtEnd(int val) { // This is code for insert ming 
        Node temp = new Node(val);
        if (head == null) {
            head = temp;
            tail = temp;
        } else {
            tail.next = temp;
            tail = temp;
        }
        size++;
    }

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public int size() {
        // Node temp = head;
        // int count = 0;
        // while(temp != null){
        // count++;
        // temp = temp.next;
        // }
        // return count;
        return size;
    }

    public void insertAtHead(int val) {
        Node temp = new Node(val);
        if (head == null) {
            head = temp;
            tail = temp;
        } else {
            temp.next = head;
            head = temp;
        }
        size++;
    }

    public void insertAt(int i, int val) {
        Node temp1 = new Node(val);
        Node temp = head;
        if (i < 0 || i > size()) {
            System.out.println("Wrong input");
            return;
        }
        if (i == 0) {
            insertAtHead(val);
            return;
        }
        if (i == size()) {
            insertAtEnd(val);
            return;
        }
        for (int j = 0; j < i - 1; j++) {
            temp = temp.next;
        }
        temp1.next = temp.next;
        temp.next = temp1;
        size++;
    }

    public int getElement(int i) {
        Node temp = head;
        if (i < 0 || i > size() - 1) {
            System.out.println("Wrong input");
            return -1;
        }
        for (int j = 0; j < i; j++) {
            temp = temp.next;
        }
        return temp.data;
    }

    public void deleteAtIndex(int i) {

        Node temp = head;
        // Node t = head.next;
        if (i == 0) {
            head = temp.next;
            size--;
            return;
        }
        if (i == size() - 1) {
            for (int k = 0; k < i - 1; k++) {
                temp = temp.next;
            }
            tail = temp;
            temp.next = null;
            size--;
            return;
        }
        for (int j = 0; j < i - 1; j++) {
            temp = temp.next;
            // t = t.next;
        }
        temp.next = temp.next.next;
        size--;
    }
}

public class ImplimentationOfLL {
    public static void main(String[] args) {
        linkedlist l = new linkedlist();
        l.insertAtHead(93);
        l.insertAtEnd(3);
        l.insertAtEnd(5);
        l.insertAtEnd(7);
        l.insertAtEnd(9);
        l.insertAtEnd(10);
        l.insertAtHead(39);
        l.insertAt(2, 0);
        // l.insertAt(8, 56);
        l.display();
        System.out.println("");
        System.out.println(l.size());
        System.out.println(l.tail.data);
        l.deleteAtIndex(0);
        l.display();
        System.out.println();
        System.out.println(l.size());
        System.out.println(l.tail.data);
        // System.out.println();
    }
}
