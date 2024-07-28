


public class LLImplementationOfStack {
    public static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data = data;
        }
    }
    public static class Stack{
        Node head = null;
        int size = 0;
        void push(int val){
            Node a = new Node(val);
            a.next = head;
            head = a;
            size++;
        }
        void displayRec(Node h){
            Node temp = h;
            if(temp == null) return;
            displayRec(temp.next);
            System.out.print(temp.data+" ");
        }
        void display(){
            displayRec(head);
            System.out.println();
        }
        void displayrev(){
            Node temp = head;
            while(temp != null){
                System.out.print(temp.data+" ");
                temp = temp.next;
            }
            System.out.println();
        }
        int pop(){
            if(head == null){
                System.out.println("Stack is empty");
                return -1;
            }
            int x = head.data;
            head = head.next;
            size--;
            return x;
        }
        int size(){
            return size;
        }
        int peek(){
            if(head == null){
                System.out.println("Stack is empty");
                return -1;
            }
            return head.data;
        }
        boolean isEmpty(){
            return size == 0;
        }

    }
    public static void main(String[] args) {
       Stack st = new Stack();
       st.push(4);
       st.display();
       st.push(3);
       st.display();
       st.push(5);
       st.display();
       st.push(2);
       st.display();
       st.pop();
       st.display();
        System.out.println(st.size());
    }
}
