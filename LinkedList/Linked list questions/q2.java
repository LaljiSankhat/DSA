// Find nth Node from end of linked list
public class q2 {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    static Node findNodeFromEnd(int i,Node head){
        Node temp = head;
        int count =0;
        while (temp != null){
            count++;
            temp = temp.next;
        }
        temp = head;
        for(int j = 0;j<count-i;i++){
            temp = temp.next;
        }
        return temp;
    }
    static Node findNodeFromEnd2(int i,Node head){
        Node slow,fast;
        slow = fast = head;
        for(int j=1;j<=i;j++){
            fast = fast.next;
        }
        while(fast != null){
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }

    public static void main(String[] args) {
        Node a = new Node(2);
        Node b = new Node(6);
        Node c = new Node(7);
        Node d = new Node(9);
        a.next = b;
        b.next = c;
        c.next = d;
        Node temp = findNodeFromEnd2(2,a);
        System.out.println(temp.data);
    }
}
