public class PrintPath {
    static void print(int sr, int sc, int er, int ec,String s){
        if(sr > er || sc > ec) return;
        if(sr == er && sc == ec){
            System.out.println(s);
            return;
        }
        // go down
        print(sr+1, sc, er, ec, s + "D");
        
        // go right 
        print(sr, sc + 1, er, ec, s+"R");
    }
    public static void main(String[] args) {
        int rows = 4;
        int cols = 4;
        print(1,1,rows,cols,"");
    }
}
