/*

Ishika got stuck on an island. There is only one shop on this island, and it is open on
all days of the week except for Sunday. Consider following constraints:

N – The maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
Currently, it’s Monday, and she needs to survive for the next S days.
Find the minimum number of days on which you need to buy food from the
shop so that she can survive the next S days, or determine that it isn’t possible to survive.

Input: S = 10, N = 16, M = 2
Output: 2
Explanation: One possible solution is to
buy a box on the first day (Monday),
it’s sufficient to eat from this box up to
8th day (Monday) inclusive. Now, on the 9th
day (Tuesday), you buy another box and use
the chocolates in it to survive the 9th and
10th day.

Input: S = 10, N = 20, M = 30
Output: -1
Explanation: She can’t survive even if
she buys food because the maximum number
of units she can buy in 1 day is less the
required food for 1 day.


*/






public class CheckIfPossibleToSurvive {
    public static int minimumDaysToBuyFood(int daysToSurvive, int maxFoodPerDay, int requiredFoodPerDay){
        int totalFoodRequired = daysToSurvive * requiredFoodPerDay;
        if(daysToSurvive > 7 && 7 * requiredFoodPerDay > 6 * maxFoodPerDay) return -1;
        int days = 0;
        while(totalFoodRequired > maxFoodPerDay) {
            System.out.println(totalFoodRequired);
            days++;
            totalFoodRequired -= maxFoodPerDay;
            System.out.println(totalFoodRequired);
        }
        if(days > daysToSurvive) return -1;
        if(totalFoodRequired == 0) return days;
        return days + 1;
    }
    public static void main(String[] args) {
        int s = 10;
        int n = 16;
        int m =  2;
        System.out.println(minimumDaysToBuyFood(s,n,m));

        // floor round to lower number while ceil round to upper number
        System.out.println(Math.floor(5.2));
        System.out.println(Math.ceil(5.2));
    }
}
