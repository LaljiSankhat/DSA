public class P2bs {
    static boolean binarySearch(int[][] a, int target) {
        int m = a[0].length;
        int n = a.length;
        int i = 0, j = m - 1;
        // int ele = a[i][j];
        while (i<n && j >= 0) {
            if (a[i][j] == target)
                return true;
            if (a[i][j] > target) {
                j--;
            } else {
                i++;
            }

        }
        return false;
    }

    public static void main(String[] args) {
        int[][] arr = { { 2, 4, 6, 8 },
                { 5, 6, 7, 20 },
                { 7, 11, 13, 25 },
                { 12, 14, 17, 30 } };
        boolean t = binarySearch(arr, 14);
        System.out.println(t);
    }
}
