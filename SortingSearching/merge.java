public class merge {
    static void merge1(int[] num1, int m, int[] num2, int n) {
        
        int j=0;
        for(int k=m;k<m+n-1;k++){
            num1[k]=num2[j++];
        }
        for(int i = 0; i<m-1;i++){
            for(int k =0; k<m-2-i;k++){
                if(num1[k]>num1[k+1]){
                    int temp = num1[k];
                    num1[k] = num1[k+1];
                    num1[k+1] = temp;
                }
            }
        }
    }
    
    public static void main(String[] args) {
       int [] a = {1,2,3,0,0,0};
       int [] b = {2,3,5,};
       merge1(a,3,b,3);
       for(int i=0;  i< a.length;i++){
        System.out.print(a+" ");
       }
    }
}
