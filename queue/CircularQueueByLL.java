
class cql {
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

    public void add(int val) {
        Node a = new Node(val);
        if (size == 0) {
            head = tail = a;
            tail.next = head;
        } else {
            tail.next = a;
            tail = a;
            tail.next = head;
        }
        size++;
    }

    public int remove() {
        if (size == 0) {
            System.out.println("Queue is empty");
            return -1;
        }
        int a = head.data;
        head = head.next;
        tail.next = head;
        size--;
        return a;
    }

    public int peek() {
        if (size == 0) {
            System.out.println("queue is empty");
            return -1;
        }
        return head.data;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        if (size == 0)
            return true;
        else
            return false;
    }

    public void display() {
        if (size == 0) {
            System.out.println("queue is empty");
            return;
        }
        Node temp = head.next;
        System.out.print(head.data+" ");
        while (temp != head) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

public class CircularQueueByLL {
    public static void main(String[] args) {
        cql q = new cql();
        q.display();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.add(5);
      
        q.add(4);
        q.add(4);
        q.add(4);

        q.add(5);
        q.display();
        // // q.remove();
        // q.display();
       
        // q.display();
        q.remove();
        q.display();

    }
}
