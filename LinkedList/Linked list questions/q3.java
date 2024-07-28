// Delete nth Node from end
public class q3 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static void display(Node head){
        Node temp = head;
//        int count = 0;
        while(temp != null){
//            count++;
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
    }
    static int size(Node head){
        Node temp = head;
        int count = 0;
        while(temp != null){
            count++;
//            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        return count;
    }
    static Node deleteNodeFromEnd(int i,Node head){
        Node slow,fast;
        slow = fast = head;
        for(int j= 0;j<i;j++){
            fast = fast.next;
        }
        if(fast == null){
            head = head.next;
            return head;
        }
        while(fast.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        slow.next = slow.next.next;
        return head;
    }
    public static void main(String[] args) {
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        display(a);
        System.out.println();
        a= deleteNodeFromEnd(4,a);
        display(a);
       // System.out.println(b.next.data);
    }
}
