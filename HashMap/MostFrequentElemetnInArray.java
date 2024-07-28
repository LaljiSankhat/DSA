
// given an array return value which apears most frequent

import java.util.HashMap;
import java.util.Map;

public class MostFrequentElemetnInArray {
    static int mostFrequent(int[] arr) {
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            if (mp.containsKey(arr[i]))
                mp.put(arr[i], mp.get(arr[i]) + 1);
            else {
                mp.put(arr[i], 1);
            }
        }
        int max = 0;
        for (var e : mp.entrySet()) {
            if (e.getValue() > max)
                max = e.getKey();
        }
        System.out.println(mp);
        return max;
    }

    public static void main(String[] args) {
        int[] a = { 1, 3, 2, 1, 6, 1 };
        System.out.println(mostFrequent(a));
    }
}
