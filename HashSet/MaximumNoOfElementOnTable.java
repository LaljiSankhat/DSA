

// you are given a bag contains pair of elements. you have to remove pair that element from bag if it present on table otherwise put it 
// on table. return the maximum no of elements on table at any given instance. 

import java.util.HashSet;

public class MaximumNoOfElementOnTable {
    static int maxNumberOnTable(int [] bag){
        HashSet<Integer> table = new HashSet<>();
        int maxSize = 0;
        int currSize = 0;
        for(int i = 0; i < bag.length; i++){
            if(table.contains(bag[i])){
                table.remove(bag[i]);
                currSize--;
            } 
            else{
                table.add(bag[i]);
                currSize++;
            }
            maxSize = Math.max(maxSize, currSize);
        }
        return maxSize;
    }
    public static void main(String[] args) {
        // int [] nums = {2,1,1,3,2,3};
        int [] nums = {1,2,3,4,5,5,4,3,2,1};
        int m = maxNumberOnTable(nums);
        System.out.println(m);
        
    }
}
