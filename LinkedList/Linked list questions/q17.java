// Copy list with random pointers --> construct a deep copy of ll where each Node contains a additional pointer


//import java.awt.*;




public class q17 {
    public static class ListNode{
        int val;
        ListNode next;
        ListNode random;
        public ListNode(int val){
            this.val = val;
        }
    }
    static void display(ListNode head){
        ListNode temp1 = head;
        while(temp1 != null){
            System.out.print(temp1.val+" ");
            temp1 = temp1.next;
        }
    }
    public static ListNode copyLLWithRandom(ListNode head){
        ListNode temp1 = head;
        ListNode head2 = new ListNode(100);
        ListNode temp2 = head2;
        // step 1 --> deep copy
        while (temp1 != null){
            ListNode a = new ListNode(temp1.val);
            temp2.next = a;
            temp2 = a;
            temp1 = temp1.next;
        }
        head2 = head2.next;
        temp1 = head;
        temp2 = head2;
        // step 2 ---> zigzag connections
        ListNode t = new ListNode(100);
        while(temp1 != null && temp2 != null){
            t.next = temp1;
            t = temp1;
            temp1 = temp1.next;

            t.next = temp2;
            t = temp2;
            temp2 = temp2.next;
        }
        temp1 = head;
        temp2 = head2;
        // ListNode of zigzag ll is z  step 3 ---> assign random pointer
        while(temp1 != null){
            if(temp1.random == null) temp2.random = null;
            else temp2.random = temp1.random.next;
            temp1 = temp1.next.next;
            if(temp2.next == null) break;
            temp2 = temp2.next.next;
        }
        temp1 = head;
        temp2 = head2;
        // step 4 --.> separating our list
        while(temp1 != null){
            temp1.next = temp2.next;
            temp1 = temp1.next;
            if(temp1 == null) break;
            temp2.next = temp1.next;
            temp2 = temp2.next;
        }
       return head2;
    }
    public static void main(String[] args) {
        ListNode a = new ListNode(7);
        ListNode b = new ListNode(13);
        ListNode c = new ListNode(11);
        ListNode d = new ListNode(10);
        ListNode e = new ListNode(1);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        a.random = null;
        b.random = a;
        c.random = e;
        d.random = c;
        e.random = a;
        display(a);
        ListNode t = copyLLWithRandom(a);
        System.out.println();
        display(t);
        System.out.println();
        System.out.println(t.next.random.val);
        System.out.println(a.next.random.val);
    }
}
