public class QuickSort {
    static int partition(int[] arr, int st, int end) {
        int pivot = arr[st];
        int cnt = 0;
        int i;
        for (i = st + 1; i < arr.length; i++) { // finding correct position of pivot
            if (arr[i] < pivot)
                cnt++;
        }
        int pivotIndex = st + cnt;
        int temp = arr[pivotIndex];
        arr[pivotIndex] = arr[st];
        arr[st] = temp;
        i = st;
        int j = end;
        while (i < pivotIndex && j > pivotIndex) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i < pivotIndex && j > pivotIndex) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        return pivotIndex;
    }

    static void quickSort(int[] arr, int st, int end) {
        if (st >= end)
            return;
        int pivot = partition(arr, st, end);
        quickSort(arr, st, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }

    public static void main(String[] args) {
        int[] arr = { 6, 43, 5, 34, 7, 2 };
        quickSort(arr, 0, 5);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
