import java.util.HashMap;
import java.util.Map;

public class BasicsOfHashMap {
    static void HashMapMethods() {
        // syntax
        Map<String, Integer> mp = new HashMap<>();
        // HashMap<String,Integer> mp = new HashMap<>(); // also valid
        // add values
        mp.put("Akash", 21);
        mp.put("yash", 16);
        mp.put("love", 17);
        mp.put("rishika", 19);
        mp.put("harry", 18);

        // get value of key from map
        System.out.println(mp.get("yash"));
        System.out.println(mp.get("rahul")); // return null because rahul does not exist in map

        // changing and updating value of key in map
        mp.put("Akash", 25);
        System.out.println(mp.get("Akash"));

        // to remove pair of map
        System.out.println(mp.remove("Akash"));
        System.out.println(mp.remove("Riya")); // return null because riya does not exist in map

        // checking a key is present or not
        System.out.println(mp.containsKey("Akash")); // false
        System.out.println(mp.containsKey("yash")); // true

        // adding new entry while key does not exist
        mp.putIfAbsent("yash", 60); // will not enter because yash is present 
        mp.putIfAbsent("yashika", 56); // will enter because yashika is present
        
        // to get all keys
        System.out.println(mp.keySet());

        // to get values of keys
        System.out.println(mp.values());

        // to get all entries of map
        System.out.println(mp.entrySet());

        // traversing in map
        for(String key : mp.keySet()){
            System.out.printf("Age of %s is %d \n",key,mp.get(key));
        }
        System.out.println();

        for(Map.Entry<String,Integer> e : mp.entrySet()){
            System.out.printf("Age of %s is %d \n",e.getKey(),e.getValue());
        }
        System.out.println();

        for(var e : mp.entrySet()){
            System.out.printf("Age of %s is %d \n",e.getKey(),e.getValue());
        }

    }

    public static void main(String[] args) {
        HashMapMethods();
    }
}
