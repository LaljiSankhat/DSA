
class queueA{
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    Node head = null;
    Node tail = null;
    int size = 0;
    public void add(int val){
       Node a = new Node(val);
       if(size == 0){
       head = tail = a;
       }
       else{
        tail.next = a;
        tail = a;
       }
       size++;
    }
    public int remove(){
        if(size == 0){
            System.out.println("Queue is empty");
            return -1;
        }
        int a = head.data;
        head = head.next;
        size--;
        return a;
    }
    public int peek(){
        if(size == 0){
            System.out.println("queue is empty");
            return -1;
        }
        return head.data;
    }
    public int size(){
        return size;
    }
    public boolean isEmpty(){
        return size == 0;
    }
    public void display(){
        if(size == 0){
            System.out.println("queue is empty");
            return;
        }
        Node temp = head;
        while(temp != null){
            System.out.print(temp.data+" ");
            temp = temp.next;
        }
        System.out.println();
    }
}
public class LLImplementationOfQueue {
    public static void main(String[] args) {
        queueA q = new queueA();
        q.display();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        q.display();
        q.remove();
        q.display();
        System.out.println(q.peek());
        System.out.println(q.size());
    }
}
