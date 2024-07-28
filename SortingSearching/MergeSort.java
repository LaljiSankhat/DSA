public class MergeSort {
    static void merge(int[] arr, int l, int mid, int r) {
        int n1 = mid + 1 - l;
        int n2 = r - mid;
        int[] left = new int[n1];
        int[] right = new int[n2];
        int i, j, k = 0;
        for (i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (j = 0; j < n2; j++){
            right[j] = arr[j + mid + 1];
        }
        i=0;j=0;k=l;
        while (i < n1 && j < n2) {
            if (left [i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }
        while (i < n1)
            arr[k++] = left[i++];
        while (j < n2)
            arr[k++] = right[j++];
    }

    static void mergeSort(int[] arr, int l, int r) {
        if (l >= r)
            return;
        int mid = (r + l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);

    }

    public static void main(String[] args) {
        int[] arr = { 6, 43, 5, 34, 7, 2 };
        mergeSort(arr, 0, 5);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
