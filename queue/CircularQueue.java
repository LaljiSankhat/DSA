
class cqa{ // circular queue by array
    int front = -1;
    int rear = -1;
    int size = 0;
    int[] arr = new int[5];
    public void add(int val) throws Exception{
        if(size == arr.length){
            // System.out.println("queue is full");
            throw new Exception("Queue is full");
        }
        else if(size == 0){
            front = rear = 0;
            arr[0] = val;
        }
        else if(rear < arr.length-1){
            arr[++rear] = val;
        }
        else if(rear == arr.length-1){
            rear = 0;
            arr[0] = val;
        }
        size++;
    }
    public int remove() throws Exception{
        if(size == 0){
            throw new Exception("Queue is full");   
        }
        else if(front == arr.length-1){
            int val = arr[front];
            front = 0;
            size--;
            return val;
        }
        else{
            int val = arr[front];
            front++;
            size--;
            return val;
        }
        
    }
    public int peek() throws Exception{
        if(size == 0){
           throw new Exception("Queue is full");
        }
        else{
            return arr[front];
        }
    }
    public boolean isEmpty(){
        if(size == 0) return true;
        else return false;
    }
    public void display(){
        if(size == 0){
            System.out.println("queue is empty");
            return;
        }
        else{
            if(front <= rear){
                for(int i = front; i <= rear; i++){
                    System.out.print(arr[i]+" ");
                }
                System.out.println();
            }
            else if(front > rear){
                for(int i = front; i < arr.length; i++){
                    System.out.print(arr[i]+" ");
                }
                for(int j = 0; j <= rear; j++){
                    System.out.print(arr[j]+" ");
                }
                System.out.println();
            }
        }
    }

}
public class CircularQueue {
    public static void main(String[] args) throws Exception {
        cqa q = new cqa();
        q.display();
        q.add(1);
        q.add(2);
        q.add(3);
        q.add(4);
        // q.add(5);
        q.display();
        // q.remove();
        q.display();
        q.add(5);
        q.display();
        q.remove();
        q.add(10);
        q.display();
        // q.add(6);
        // q.display();
        // q.add(10);
        for(int i = 0; i < q.arr.length; i++){
            System.out.print(q.arr[i]+" ");
        }
    }
}
