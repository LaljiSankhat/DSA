public class p3bsPeak {
    static int binarySearch(int[] a) {
        int st = 0;
        int end = a.length - 1;
        int mid = st + (end - st) / 2;
        int ans = -1;
        while (st <= end) {
            mid = st + (end - st) / 2;
            if (a[mid] < a[mid + 1]) {
                ans = mid + 1;
                st = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 3, 2, 1 };
        // . System.out.println(binarySearch(arr,5));
        int m = binarySearch(arr);
        System.out.println(m);
    }
}
