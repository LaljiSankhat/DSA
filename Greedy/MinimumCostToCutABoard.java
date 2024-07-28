/*

  A board of length M and width N is given. The task is to break this board into M * N squares
  such that cost of breaking is minimum. The cutting cost for each edge will be given for the board
  in two arrays X[] and Y[]. In short, you need to choose such a sequence of cutting such that cost
  is minimized. Return the minimized cost.

  Example 1:

Input:
M = 6. N = 4
X[] = {2, 1, 3, 1, 4}
Y[] = {4, 1, 2}
Output: 42
Explanation:

For above board optimal way to cut into square is:
Total minimum cost in above case is 42. It is
evaluated using following steps.
Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces
Cost 4 Horizontal cut:      Cost = 0 + 4*1 = 4
Cost 4 Vertical cut:        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut:        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut:      Cost = 18 + 2*3 = 24
Cost 2 Vertical cut:        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut:      Cost = 30 + 1*4 = 34
Cost 1 Vertical cut:        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut:        Cost = 38 + 1*4 = 42


Example 2:

Input:
M = 4, N = 4
X[] = {1, 1, 1}
Y[] = {1, 1, 1}
Output: 15
Explanation:

For above board optimal way to cut into square is:
Total minimum cost in above case is 15.
It is evaluated using following steps.
Initial Value :
Total_cost = 0 Total_cost = Total_cost + edge_cost * total_pieces
Cost 1 Horizontal cut: Cost = 0 + 1*1 = 1
Cost 1 Horizontal cut: Cost = 1 + 1*1 = 2
Cost 1 Horizontal cut: Cost = 2 + 1*1 = 3
Cost 1 Vertical cut:   Cost = 3 + 1*4 = 7
Cost 1 Vertical cut:   Cost = 7 + 1*4 = 11
Cost 1 Vertical cut:   Cost = 11 + 1*4 = 15


 */


import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MinimumCostToCutABoard {
    public static int minimumCost(List<Integer> verticalCuts, List<Integer> horizontalCuts, int m, int n){
        int noOfVerticalPiece = 1;
        int noOfHorizontalPiece = 1;
        int totalCost = 0;
        verticalCuts.sort(Comparator.reverseOrder());
        horizontalCuts.sort(Comparator.reverseOrder());
        int i = 0, j = 0;
        while(i < m - 1 && j < n - 1){
            if(verticalCuts.get(i) >= horizontalCuts.get(j)){
                totalCost += verticalCuts.get(i) * noOfHorizontalPiece;
                noOfVerticalPiece++;
                i++;
            }else{
                totalCost += horizontalCuts.get(j) * noOfVerticalPiece;
                noOfHorizontalPiece++;
                j++;
            }
        }
        while(i < m - 1){
            totalCost += verticalCuts.get(i) * noOfHorizontalPiece;
            noOfVerticalPiece++;
            i++;
        }
        while(j < n - 1){
            totalCost += horizontalCuts.get(j) * noOfVerticalPiece;
            noOfHorizontalPiece++;
            j++;
        }
        return totalCost;

    }
    public static void main(String[] args) {
        List<Integer> x = new ArrayList<>(); // verticalCuts
        x.add(2);
        x.add(1);
        x.add(3);
        x.add(1);
        x.add(4);
        List<Integer> y = new ArrayList<>(); // horizontalCuts
        y.add(4);
        y.add(1);
        y.add(2);
        int ans = minimumCost(x,y,x.size() + 1,y.size() + 1);
        System.out.println(ans);
    }
}
