import java.util.Comparator;
// import java.util.HashSet;
import java.util.PriorityQueue;

public class BasicsOfPriorityQueue {
    private static class Student{
        String name;
        int rollNo;
        int mark;
        String dob;
    }
    private static class StudentComparator implements Comparator<Student>{
        // overriding
        public int compare(Student s1, Student s2){
            if(s1.mark > s2.mark) return -1;
            else if(s1.mark < s2.mark) return 1;
            else {
                if(s1.rollNo > s2.rollNo) return -1;
                else if(s1.rollNo < s2.rollNo) return 1;
                else return 0;
            }
        }
    }
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // default capacity 11
        pq.add(12);
        pq.add(2);
        pq.add(20);
        pq.add(15);
        pq.add(7);
        pq.add(1);
        System.out.println(pq); // converted into Min heap by default in java but in c++ this is max heap default

        // defining priorities
        PriorityQueue<Integer> pq2 = new PriorityQueue<>(20); // capacity become 20
        PriorityQueue<Integer> pq3 = new PriorityQueue<>(pq); // copy of first


        // to give logic for priority we use comparator
        PriorityQueue<Integer> pqMax = new PriorityQueue<>(Comparator.reverseOrder());
        pqMax.add(20);
        pqMax.add(21);
        pqMax.add(2);
        pqMax.add(5);
        pqMax.add(210);
        pqMax.add(34);
        System.out.println(pqMax); // max heap

        PriorityQueue<Student> students = new PriorityQueue<>(new StudentComparator()); // min heap by default
        Student Lalji = new Student();
        Lalji.name = "Lalji";
        Lalji.mark = 100;
        Lalji.rollNo = 131;
        Lalji.dob = "03-06-2005";
        students.add(Lalji);
        Student jay = new Student();
        jay.name = "Jay";
        jay.mark = 100;
        jay.rollNo = 152;
        jay.dob = "06-03-2005";
        students.add(jay);
        System.out.println(students.peek().dob);
        System.out.println(students.peek().name);
        System.out.println(students.peek().rollNo);
        System.out.println(students.peek().mark);






    }
}
