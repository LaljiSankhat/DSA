package HashMapQuetions;

import java.util.HashMap;

// return true if both strings are anagram else false
// anagram of a string is  that contains the same character of other string example [silent, listen] in this 
// they have same characters also equal frequency
// 1. length same , 2.frequency of each char same , 3.no character shold be extra 
public class ValidAnagram {
    private static void putValues(HashMap<Character,Integer> mp,String s){
        for(int i = 0; i < s.length(); i++){
            char ch = s.charAt(i);
            if(mp.containsKey(ch)){
                mp.put(ch,mp.get(ch) + 1);
            }
            else{
                mp.put(ch,1);
            }            
        }
    }
    static boolean isAnagram(String s1, String s2){
        if(s1.length() != s2.length()) return false;
        HashMap<Character,Integer> mp1 = new HashMap<>();
        HashMap<Character,Integer> mp2 = new HashMap<>();
        // traversing and putting values in string 1
        putValues(mp1,s1);

        // traversing and putting values in string s2
        putValues(mp2,s2);

        // checking both map are same or not if same then true else false
        for(var e1 : mp1.entrySet()){
            if(!mp2.containsKey(e1.getKey()) || mp2.get(e1.getKey()) != e1.getValue()){
                return false;
            }
        }
        // this is also done by map equal functions
        // return mp1.equals(mp2);
        
        return true;        
    }
    // space optimesed solution 
    static boolean isAnagramSpaceOptimised(String s1, String s2){
        if(s1.length() != s2.length()) return false;
        HashMap<Character,Integer> mp1 = new HashMap<>();
        putValues(mp1, s1);
        for(int i = 0; i < s2.length(); i++){
            char ch = s2.charAt(i);
            if(mp1.containsKey(ch)){
                mp1.put(ch, mp1.get(ch) - 1);
                if(mp1.get(ch) - 1 < 0) return false;
            }
            else{
                return false;
            }                    
        }
        // traversing map 
        for(var e : mp1.entrySet()){
            if(e.getValue() != 0) return false;
        }
        return true;
    } 
    public static void main(String[] args) {
        String s1 = "silent";
        String s2 = "listen";
        // String s1 = "s";
        // String s2 = "s";
        // boolean b = isAnagram(s1,s2);
        boolean b = isAnagramSpaceOptimised(s1, s2);
        System.out.println(b);
        
    }
}
