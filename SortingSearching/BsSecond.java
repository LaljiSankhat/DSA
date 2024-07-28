import java.util.Scanner;

class Node{
    
}
public class BsSecond {
    static boolean binarySearch(int [][] a,int target){
        // n rows and m cols
        int n= a.length, m=a[0].length;  
        int st =0, end = n*m-1;
        while(st<=end){
           int mid = st + (end - st)/2;
           int midEle = a[mid/m][mid%m];
           if(midEle == target) return true;
           if(midEle < target){
            st = mid + 1;
           }
           else{
            end = mid -1;
           }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] arr = { { 1, 3, 5, 7 },
                { 10, 11, 16, 20 },
                { 23, 30, 34, 60 } };
        boolean t= binarySearch(arr, 16);
         System.out.println(t);       // System.out.println(binarySearch(arr, 0, 0, 2, 3, 11, 3, 2));
        Scanner sc = new Scanner(System.in);
        // int a = sc.
        sc.close();
    }

}
