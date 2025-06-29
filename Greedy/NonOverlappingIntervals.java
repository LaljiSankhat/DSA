/*

  Given an array of intervals intervals where intervals[i] = [starti, endi],
  return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.



Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.


* */


import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class NonOverlappingIntervals {
    private static class Interval{
        int startTime;
        int endTime;
        public Interval(int startTime,int endTime){
            this.startTime = startTime;
            this.endTime = endTime;
        }
        public String toString(){
            return startTime + "-" + endTime;
        }
    }

    private static class IntervalComparator implements Comparator<Interval>{
        public int compare(Interval i1, Interval i2){
            if(i1.startTime < i2.startTime) return -1;
            else if(i1.startTime > i2.startTime) return 1;
            else return 0;
        }
    }
    public static int nonOverlapping(List<Interval> intervals){
            intervals.sort(new IntervalComparator());
            int result = 0;
    //        System.out.println(intervals);
            int previousEndTime = intervals.get(0).endTime;
            for(int i = 1; i < intervals.size(); i++){
                Interval current = intervals.get(i);
                // check overlapping and REMOVE
                if(current.startTime < previousEndTime){ // overlapping hain
                    // chhote ko previous banao
                    previousEndTime = Math.min(current.endTime,previousEndTime);
                    result++;
                }else{
                    previousEndTime = current.endTime;
                }
            }
            return result;
    }
    public static void main(String[] args) {
//        int[][] a = {{1,2},{2,3},{3,4},{1,3}};
//        Arrays.sort(a, Comparator.comparingInt(arr -> arr[0]));
//        for(int i = 0; i < a.length; i++){
//            for(int j = 0; j < a[i].length; j++){
//                System.out.print(a[i][j] + " ");
//            }
//            System.out.println();
//        }
//        System.out.println(a);

        List<Interval> intervalList = new ArrayList<>();
        intervalList.add(new Interval(1,2));
        intervalList.add(new Interval(2,3));
        intervalList.add(new Interval(3,4));
        intervalList.add(new Interval(1,3));
        int a = nonOverlapping(intervalList);
        System.out.println(a);
    }
}


/*
  LeetCode 435

  class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(arr -> arr[0]));
        int result = 0;
        int previousEndTime = intervals[0][1];
        for(int i = 1; i < intervals.length; i++){
            if(intervals[i][0] < previousEndTime){
                previousEndTime = Math.min(intervals[i][1],previousEndTime);
                result++;
            }else{
                previousEndTime = intervals[i][1];
            }
        }
        return result;
    }
}



optimised

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {

        Arrays.sort( intervals , ( int a[] , int b[] ) ->  a[1] - b[1] );
        // Arrays.sort( intervals , ( int a[] , int b[]) -> a[0] - b[0] );

        int start = intervals[0][0];
        int end = intervals[0][1];

        int count = 0;

        for( int i = 1 ; i < intervals.length ; i++ )
        {
            int now_start = intervals[i][0];
            int now_end = intervals[i][1];

            if( now_start < end )
                {
                    count++;
                    continue;
                }

            else
            {
                end = now_end;
            }
        }

        return  count;
    }
}
* */
