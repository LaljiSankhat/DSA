import java.util.*;
import java.lang.String;

class BookStore {

    private int ISBN;
    private String name;
    private String author;
    private float price;

    /*
     * BookStore(int ISBN, String name, String author, float price){
     * this. ISBN = ISBN;
     * this.name = name;
     * this.author = author;
     * this.price = price;
     * }
     */
    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setISBN(int isbn) {
        this.ISBN = isbn;
    }

    public int getISBN() {
        return this.ISBN;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public String getAuthor() {
        return this.author;
    }

    public void setPrice(float price) {
        this.price = price;
    }

    public float getPrice() {
        return this.price;
    }

    public static int getRecord(BookStore[] record, int ISBN) {

        for (int i = 0; i <= Ashok.getNoOfBooks(); i++) {
            if (record[i].getISBN() == ISBN)
                return i;
        }

        return -1;
    }

    public static void printAllRecord(BookStore[] record) {
        int c = 0;

        if (BookStore.isEmptyRecord())
            System.out.println("No Records Found.");
        else {
            for (int i = 0; i <= Ashok.i; i++) {
                System.out.println("(" + (++c) + ").ISBN Number : " + record[i].getISBN() + "\n    Book Name : "
                        + record[i].getName() + "\n    Author Name : " + record[i].getAuthor() + "\n    Price : "
                        + record[i].getPrice());
            }
        }

    }

    public static void searchRecord(BookStore[] record, String name) {

        int c = 0;

        for (int i = 0; i <= Ashok.getNoOfBooks(); i++) {
            if (record[i].getName().toLowerCase().contains(name.toLowerCase()))
                System.out.println("(" + (++c) + ").Book Name : " + record[i].getName() + "\n    ISBN Number : "
                        + record[i].getISBN() + "\n    Author Name : " + record[i].getAuthor() + "\n    Price : "
                        + record[i].getPrice());
        }
        if (c == 0)
            System.out.println("No Books Found for Provided Name.");
    }

    public static void updateRecord(BookStore[] record, int isbn) {
        Scanner sc = new Scanner(System.in);
        float price;
        String book_name, author;
        int i = getRecord(record, isbn);

        if (i < 0)
            System.out.println("Book Record Not Found for Provided ISBN Number.");
        else {
            System.out.println("Update The Record Field You Want by pressing 'Y' : Otherwise Press 'N'.");
            System.out.print("Do You Want To Update ISBN Number of Book (Y/N) : ");
            char choice = sc.nextLine().toLowerCase().charAt(0);
            if (choice == 'y') {
                System.out.print("Enter the NEW ISBN Number of Book : ");
                isbn = sc.nextInt();
                record[i].setISBN(isbn);
            }
            System.out.print("Do You Want To Update Book Name (Y/N) : ");
            choice = sc.nextLine().toLowerCase().charAt(0);
            if (choice == 'y') {
                System.out.print("Enter the Book Name : ");
                book_name = sc.nextLine();
                record[i].setName(book_name);
            }
            System.out.print("Do You Want To Update Author Name (Y/N) : ");
            choice = sc.nextLine().toLowerCase().charAt(0);
            if (choice == 'y') {
                System.out.print("Enter the Book Name : ");
                author = sc.nextLine();
                record[i].setAuthor(author);
            }
            System.out.print("Do You Want To Update Price of Book (Y/N) : ");
            choice = sc.nextLine().toLowerCase().charAt(0);
            if (choice == 'y') {
                System.out.print("Enter the Price of Book : ");
                price = sc.nextInt();
                record[i].setPrice(price);
            }
        }
        sc.close();
    }

    public static boolean deleteRecord(BookStore[] record, int isbn) {
        int i = getRecord(record, isbn), j;
        if (i < 0)
            return false;
        else {
            for (j = i; j < Ashok.getNoOfBooks(); j++) {
                record[j] = record[j + 1];
            }
            record[j] = null;
            return true;
        }
    }

    public static boolean isFullRecord() {
        return Ashok.getNoOfBooks() == Ashok.SIZE - 1;
    }

    public static boolean isEmptyRecord() {
        return Ashok.i == -1;
    }
    // sc.close();
}

public class Ashok {
    static int i = -1;
    final static int SIZE = 5;

    public static int getNoOfBooks() {
        return i;
    }

    public static void main(String[] args) {
        System.out.println("*-------------------------*");
        System.out.println("|  WELCOME to E-library   |");
        System.out.println("*-------------------------*");

        int isbn;

        float price;

        String book_name, author, str, choice;

        Scanner sc = new Scanner(System.in);
        BookStore[] record = new BookStore[SIZE];

        System.out.println(">Enter the Following Commands\n To Insert->(1)\tTo update->(2)\tTo Search->(3)\tTo Delete->(4)\tTo Print All Records->(6)\tTo Exit->(exit).");

        do {
            System.out.print("\nEnter the Choice (Menu->5) : ");
            choice = sc.nextLine().toLowerCase();

            switch (choice) {

                case "exit":
                    break;

                case "1":
                    if (BookStore.isFullRecord()) {
                        System.out.println("Book Store Records Are Full!!!!");
                        break;
                    }
                    Ashok.i++;
                    System.out.print("Enter the ISBN Number: ");
                    str = sc.nextLine();
                    isbn = Integer.parseInt(str);

                    System.out.print("Enter the Book Name: ");
                    book_name = sc.nextLine();

                    System.out.print("Enter the Author Name: ");
                    author = sc.nextLine();

                    System.out.print("Enter the Price of Book: ");
                    str = sc.nextLine();
                    price = Float.parseFloat(str);

                    record[i] = new BookStore();

                    record[i].setISBN(isbn);
                    record[i].setName(book_name);
                    record[i].setAuthor(author);
                    record[i].setPrice(price);

                    // record[i] = new BookStore(isbn,book_name,author,price);
                    break;

                case "2":
                    if (BookStore.isEmptyRecord())
                        System.out.println("No Books Are Available In The The Book Store For Search");
                    else {
                        System.out.print("Enter the ISBN Number for Update : ");
                        str = sc.nextLine();
                        isbn = Integer.parseInt(str);
                        BookStore.updateRecord(record, isbn);
                    }
                    break;

                case "3":
                    if (BookStore.isEmptyRecord())
                        System.out.println("No Books Are Available In The The Book Store For Search");
                    else {
                        System.out.print("Enter the Book Name for Search: ");
                        book_name = sc.nextLine();
                        BookStore.searchRecord(record, book_name.strip());
                    }
                    break;

                case "4":
                    if (BookStore.isEmptyRecord())
                        System.out.println("No Books Are Available In The The Book Store");
                    else {
                        System.out.print("Enter the ISBN Number for Delete : ");
                        str = sc.nextLine();
                        isbn = Integer.parseInt(str);
                        if (BookStore.deleteRecord(record, isbn)) {
                            System.out.println("Record Deleted Successfully....");
                            Ashok.i--;
                        } else
                            System.out.println("Book Record Not Found for Provided ISBN Number.");
                    }
                    break;

                case "5":
                    System.out.println("To Insert -> 1\tTo Search->2\tTo Delete -> 3\tTo update -> 4\tTo Exit->0.");
                    break;

                case "6":
                    BookStore.printAllRecord(record);
                    break;
                default:
                    System.out.println("Please Enter the Valid Choice!!!");

            }
        } while (!choice.equals("exit"));
        sc.close();
    }
}

class StringCheck {
    public static boolean checkSubString(String str, String sub_str) {
        if (sub_str.length() == 0 || str.length() < sub_str.length())
            return false;

        for (int i = 0, j = 0; i < str.length() - sub_str.length() + 1; i++) {

            for (j = 0; i < str.length() && str.charAt(i) == sub_str.charAt(j); j++, i++) {
                if (j == sub_str.length() - 1)
                    return true;
            }
            if (j != 0)
                i--;
        }
        return false;
    }
}
