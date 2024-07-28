/*
Given weights and values of N items, we need to put these items in a knapsack of
capacity W to get the maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item.

Example 1:

Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack.

Example 2:

Input:
N = 2, W = 50
values[] = {60,100}
weight[] = {10,20}
Output:
160.00
Explanation:
Total maximum value of item
we can have is 160.00 from the given
capacity of sack.
* */


import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class FractionalKnapsack {
    private static class Item {
        int value;
        int weight;

        public String toString() {
            return value + " " + weight;
        }
    }

    private static class ItemComparator implements Comparator<Item> {
        public int compare(Item i1, Item i2) {
            if ((i1.value / i1.weight) < (i2.value / i2.weight)) return 1;
            else if ((i1.value / i1.weight) > (i2.value / i2.weight)) return -1;
            else return 0;
        }
    }

    public static void main(String[] args) {
        List<Integer> values = List.of(60, 100, 150, 120);
        List<Integer> weights = List.of(10, 20, 50, 15);
        List<Item> itemsList = new ArrayList<>();
        for (int i = 0; i < values.size(); i++) {
            Item item = new Item();
            item.value = values.get(i);
            item.weight = weights.get(i);
            itemsList.add(item);
        }
        System.out.println(itemsList);
        itemsList.sort(new ItemComparator());
        System.out.println(itemsList);
        int w = 30;
        int profit = 0;
        for (int i = 0; i < itemsList.size() && w > 0; i++) {
            Item item = itemsList.get(i);
            if (item.weight <= w) {
                profit += item.value;
                w -= item.weight;
            } else {
                profit += (item.value / item.weight) * w;
                w = 0;
            }
        }

        System.out.println(profit);
    }
}
