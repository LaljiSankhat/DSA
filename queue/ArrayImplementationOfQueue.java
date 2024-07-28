
class queue{
    int [] arr = new int[100];
    int f = -1;
    int r = -1;
    int size = 0;
    public void add(int val){
        if(r == arr.length-1){
            System.out.println("queue is full");
            return;
        }
        if(f == -1){
            f = r = 0;
            arr[r] = val;
        }
        else{
            arr[++r] = val;
        }
        size++;
    }
    public int remove(){
        if(size <= 0){
            System.out.println("queue is empty");
            return -1;
        }
        int a = arr[f++];
        size--;
        return a;
    }
    public int peek(){
        if(size <= 0){
            System.out.println("queue is empty");
            return -1;
        }
        return arr[f];
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
        for(int i = f; i <= r; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public int size(){
        return size;
    }
}

public class ArrayImplementationOfQueue {
    public static void main(String[] args) {
        queue q = new queue();
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
