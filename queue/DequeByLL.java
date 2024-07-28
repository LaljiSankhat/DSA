

class ListNode{
    int data;
    ListNode next;
    ListNode pre;
    public ListNode(int data){
        this.data = data;
    }
}
class dequeL{
    ListNode head = null;
    ListNode tail = null;
    int size = 0;
    public void addFirst(int val){
        ListNode a = new ListNode(val);
        if(size == 0){
            head = tail = a;
        }
        else{
            head.pre = a;
            a.next = head;
            head = a;
        }
        size++;
    }
    public void addLast(int val){
        ListNode a = new ListNode(val);
        if(size == 0){
            head = tail = a;
        }
        else{
            tail.next = a;
            a.pre = tail;
            tail = a;
        }
        size++;
    }
    public int removeFirst(){
        if(size == 0){
            System.out.println("queue is empty");
            return -1;
        }
        else{
            int val = head.data;
            head = head.next;
            size--;
            return val;
        }
        
    }
    public int removeLast(){
        if(size == 0){
            System.out.println("queue is empty");
            return -1;
        }
        else{
            int val = tail.data;
            tail = tail.pre;
            tail.next = null;
            size--;
            return val;
        }
        
    }
    public int getFirst(){
        if(size == 0){
            System.out.println("queue is empty");
            return -1;
        }
        else return head.data;
    }
    public int getLast(){
        if(size == 0){
            System.out.println("queue is empty");
            return -1;
        }
        else return tail.data;
    }
    public void display(){
        ListNode temp = head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }

}

public class DequeByLL {
    public static void main(String[] args) {
        dequeL dq = new dequeL();
        dq.addLast(1);
        dq.addLast(2);
        dq.addLast(3);
        dq.addLast(4);
        dq.addFirst(5);
        dq.display();
        dq.removeLast();
        dq.display();
        dq.removeFirst();
        dq.display();
        // System.out.println(dq.peekFirst());
        System.out.println(dq.getFirst());
        // System.out.println(dq.peekLast());
        System.out.println(dq.getLast());
    }
}
