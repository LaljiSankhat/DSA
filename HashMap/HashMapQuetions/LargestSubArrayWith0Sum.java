package HashMapQuetions;

import java.util.HashMap;

//  given array of length n we have to return length of largest subarra whose sum is 0
// exa : {15,-2,2,-8,1,7,10,23}  length = 5 --> {-2,2,-8,1,7}
public class LargestSubArrayWith0Sum {
    static int largestSubArray(int [] arr){
        int maxLength = 0;
        HashMap<Integer,Integer> mp = new HashMap<>();
        mp.put(0, -1);
        int ps = 0;
        for(int i = 0; i < arr.length; i++){
            ps = ps + arr[i];
            // mp.put(ps, i);
            if(!mp.containsKey(ps)) mp.put(ps, i);
            else {
                // maxLength = i - mp.get(ps);
                maxLength = Math.max(maxLength, i - mp.get(ps));
            }
        }
        return maxLength;

    }
    public static void main(String[] args) {
        int [] arr = {15,-2,2,-8,1,7,10,-25};
        int a = largestSubArray(arr);
        System.out.println(a);
    }
}
