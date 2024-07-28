/**
 * BinarySearch
 */
public class BinarySearch {
    static int binarySearch(int[] arr, int target, int st, int end) {
        // int Index;
        int mid = st + (end - st) / 2;
        while (st != end) {
            mid = st + (end - st) / 2;
            if (arr[mid] > target)
                end = mid - 1;
            else if (arr[mid] < target)
                st = mid + 1;
            if (arr[mid] == target)
                return mid;
        }
        return mid;
    }

    public static void main(String[] args) {
        int [] arr = { 6, 43, 5, 34, 7, 2 };
        System.out.println(binarySearch(arr, 5, 0, 5)); 
    }
}