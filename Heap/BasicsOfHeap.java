import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class BasicsOfHeap {
    public static void swap(List<Integer> heap,int parentIndex,int idx){
        int temp = heap.get(parentIndex);
        heap.set(parentIndex, heap.get(idx));
        heap.set(idx,temp);
    }

    public static void pushUpInMinHeap(List<Integer> heap, int idx){
        // until root reached / correct position found
        int parentIndex = (idx - 1) / 2;
        if(idx == 0 || heap.get(parentIndex) < heap.get(idx)){
           return;
        }
        // swap
        swap(heap,parentIndex,idx);
        pushUpInMinHeap(heap,parentIndex);
    }
    public static void insertInMinHeap(List<Integer> heap, int val){
        heap.add(val);
        int idx = heap.size() - 1;
        pushUpInMinHeap(heap,idx);
    }
    // insert in max heap
    public static void pushUpInMaxHeap(List<Integer> heap,int idx){
        int parentIndex = (idx - 1) / 2;
        if(idx == 0 || heap.get(parentIndex) > heap.get(idx)) return;
        swap(heap,parentIndex,idx);
        pushUpInMaxHeap(heap,parentIndex);
    }
    public static void insertInMaxHeap(List<Integer> heap, int val){
        heap.add(val);
        int idx = heap.size() - 1;
        pushUpInMaxHeap(heap,idx);
    }

    // delete from Minheap
    public static void deleteFromMinHeap(List<Integer> heap){
        swap(heap,0,heap.size() - 1);
        heap.remove(heap.size() - 1);
        pushDownInMinHeap(heap,0);
    }

    public static void heapify(List<Integer> heap,int start,int end){ // to build heap
        int firstNonLeafNode = (end - 1) / 2;
        for(int i = firstNonLeafNode; i >= 0; i--){
            pushDownInMinHeap(heap,i);
        }
    }
    private static void pushDownInMinHeap(List<Integer> heap, int parentIndex) {
        if(parentIndex == heap.size() - 1) return;
        int n = heap.size() - 1;
        int leftChild = (2 * parentIndex) + 1;
        int rightChild = (2 * parentIndex) + 2;
        int smallest = parentIndex;
        if(leftChild <= n && heap.get(leftChild) < heap.get(smallest)) smallest = leftChild;
        if(rightChild <= n && heap.get(rightChild) < heap.get(smallest)) smallest = rightChild;
        if(parentIndex == smallest) return;
        swap(heap,parentIndex,smallest);
        pushDownInMinHeap(heap,smallest);
//        if(parentIndex == heap.size() - 1 || heap.get(parentIndex) < Math.min(heap.get(leftChild), heap.get(rightChild))){
//            return;
//        }
//        if (rightChild <= heap.size() - 1 && heap.get(leftChild) > heap.get(rightChild)) {
//            swap(heap, parentIndex, rightChild);
//            pushDownInMinHeap(heap,rightChild);
//        }
//        else if (leftChild <= heap.size() - 1 && heap.get(leftChild) < heap.get(rightChild)){
//            swap(heap, parentIndex, leftChild);
//            pushDownInMinHeap(heap,leftChild);
//        }

    }

    // deletion in max Heap
    public static void deleteFromMaxHeap(List<Integer> heap){
        swap(heap,0,heap.size() - 1);
        heap.remove(heap.size() - 1);
        pushDownInMaxHeap(heap,0);
    }

    private static void pushDownInMaxHeap(List<Integer> heap, int parentIndex) {
        if(parentIndex == heap.size() - 1) return;
        int n = heap.size() - 1;
        int leftChild = (2 * parentIndex) + 1;
        int rightChild = (2 * parentIndex) + 2;
        int greater = parentIndex;
        if(leftChild <= n && heap.get(leftChild) > heap.get(greater)) greater = leftChild;
        if(rightChild <= n && heap.get(rightChild) > heap.get(greater)) greater = rightChild;
        if(parentIndex == greater) return;
        swap(heap,parentIndex,greater);
        pushDownInMaxHeap(heap,greater);
    }


    public static void heapSort(List<Integer> arr/*,List<Integer> ans*/){
        heapify(arr,0,arr.size() - 1);
        System.out.println(arr);
        int n = arr.size() - 1;
        for(int i = n; i > 0; i--){
            swap(arr,0,i);
//            ans.add(arr.remove(i));
            heapify(arr,0,i-1);
        }
    }
    public static void main(String[] args) {
        List<Integer> heap = new ArrayList<>();
//        heap.add(10);
//        heap.add(20);
//        heap.add(30);
//        heap.add(40);
//        heap.add(50);
//        deleteFromMinHeap(heap);
//        System.out.println(heap);
//        insertInMinHeap(heap,15);
//        System.out.println(heap);

//        heap.add(50);
//        heap.add(40);
//        heap.add(30);
//        heap.add(20);
//        heap.add(10);
//        insertInMaxHeap(heap,45);
//        System.out.println(heap);
//        deleteFromMaxHeap(heap);
//        System.out.println(heap);
//        heapify(heap);
//        System.out.println(heap);
//        System.out.println("Sankhat Lalji Rajubhai");
        List<Integer> arr = new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        arr.add(10);
        arr.add(12);
        arr.add(16);
        arr.add(20);
        arr.add(5);
        arr.add(1);
        System.out.println(arr);
        heapSort(arr);
        System.out.println(arr);
//        int[] l = {3,2,5,1,5,7};
//        System.out.println();

    }
}
