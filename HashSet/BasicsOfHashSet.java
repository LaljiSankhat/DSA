import java.util.HashSet;

public class BasicsOfHashSet {
    public static void main(String[] args) {
        // it is as same as HashMap but here we only have key not value --> only one parameter 
        // in this only unique key are present
        HashSet<String> st = new HashSet<>();
        // to add
        st.add("Krishna");
        st.add("Ganesh");
        st.add("Mahadev");
        st.add("Mahadev");
        System.out.println(st); // krishna ganesh mahadev not another mahadev because it already exist

        System.out.println(st.contains("Krishna")); // true

        System.out.println(st.size()); // 3

        st.remove("Ganesh");
        System.out.println(st.contains("Ganesh")); // false
        System.out.println(st.size()); // 2

        st.add("ganesh");

        for(String s : st){
            System.out.print(s+" ");
        }
    }
}
