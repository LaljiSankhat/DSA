import java.util.Stack;

public class Infix {
    public static void main(String[] args) {
        String str = "8-5+3*4/6";
        Stack<Integer> val = new Stack<>();
        Stack<Character> op = new Stack<>();
        for(int i = 0 ; i< str.length(); i++){
            char ch = str.charAt(i);
            int ascii = (int)ch;
            // ascii values of '0' --> 48  '9' --> 57
            if(ascii <= 57 && ascii >= 48){
                val.push(ascii - 48);
            }
            else if(op.size() == 0){
                op.push(ch);
            }
            else{
                if(ch == '+' || ch == '-'){
                    // work niptao
                    int v2 = val.pop();
                    int v1 = val.pop();
                    if(op.peek() == '-') val.push(v1 - v2);
                    else if(op.peek() == '+') val.push(v1 + v2);
                    else if(op.peek() == '*') val.push(v1 * v2);
                    else if(op.peek() == '/') val.push(v1 / v2);
                    op.pop();
                    op.push(ch);
                }
                if(ch == '*' || ch == '/'){
                    if(op.peek() == '*' || op.peek() == '/'){
                        int v2 = val.pop();
                        int v1 = val.pop();
                        if(op.peek() == '*') val.push(v1 * v2);
                        else if(op.peek() == '/') val.push(v1 / v2);
                        op.pop();
                        op.push(ch);
                    }
                    else op.push(ch);
                }
            }
        }
        while(val.size() > 1){
            // work
            int v2 = val.pop();
            int v1 = val.pop();
            if(op.peek() == '-') val.push(v1 - v2);
            else if(op.peek() == '+') val.push(v1 + v2);
            else if(op.peek() == '*') val.push(v1 * v2);
            else if(op.peek() == '/') val.push(v1 / v2);
            op.pop();
        }
        System.out.println(val.peek());

    }
}
