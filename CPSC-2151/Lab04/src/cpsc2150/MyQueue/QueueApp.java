package cpsc2150.MyQueue;

import java.util.Scanner;

public class QueueApp {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String userAnswer;
        IQueue q;

        System.out.println("Do you want an array (Type array) or list implementation? (Type list) ");
        userAnswer = scanner.nextLine();
        userAnswer = userAnswer.toLowerCase();

        if (userAnswer.compareTo("list") == 0) {
            System.out.println("Entered List");
            Integer x = 42;
            q = new ListQueue();
            q.enqueue(x);
            x = 17;
            q.enqueue(x);
            x = 37;
            q.enqueue(x);
            x = 36;
            q.enqueue(x);
            x = 12;
            q.enqueue(x);

            /* TODO print all elements */
            q.printList();


        } else if (userAnswer.compareTo("array") == 0) {
            System.out.println("Entered array");
            Integer x = 42;
            q = new ArrayQueue();
            q.enqueue(x);
            x = 17;
            q.enqueue(x);
            x = 37;
            q.enqueue(x);
            x = 36;
            q.enqueue(x);
            x = 12;
            q.enqueue(x);

            /* TODO print all elements I wasnt sure how to do it without
             *  having a method inside the class */
            q.printList();

        } else {
            System.out.println("Invalid Input");
        }
    }
}

