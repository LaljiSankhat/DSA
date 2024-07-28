package HashMapQuetions;

import java.util.HashMap;

// two string are isomorphic if the chars of s1 can be replaced to get s2 also no two charcter replaced by one character
// exa : aab , xxy  here we replace a by x and b by y we get string 2
// exa : lalji , shsda  here we replace l-s and a-y and j-d and i-a we get string 2
/*
 * Input: s = "egg", t = "add"
   Output: true
 */
public class Isomorphic {
    static boolean isIsomorphic(String s1, String s2){
        if(s1.length() != s2.length()) return false;
        HashMap<Character,Character> mp = new HashMap<>();      
        for(int i = 0; i < s1.length(); i++){
            char ch = s1.charAt(i);
            char ch2 = s2.charAt(i);
            if(mp.containsKey(ch) && mp.get(ch) != ch2) return false;
            if(!mp.containsKey(ch) && mp.containsValue(ch2)) return false; // checking no two charcter replaced by one character
            else mp.put(ch, ch2);            
        }
        return true;
    }
    public static void main(String[] args) {
        String s = "need";
        String t = "kllk";
        System.out.println(isIsomorphic(s, t));
        
    }
}
