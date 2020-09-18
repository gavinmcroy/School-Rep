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

            x = q.dequeue();
            System.out.println(x);


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

            /* TODO print all elements */
            x = q.dequeue();
            System.out.println(x);

        } else {
            System.out.println("Invalid Input");
        }

        /** @Question
         * Do we add java doc comments to implemented classes or do these comments
         * just stay inside the interface
         * Where do method contracts go?
         * What exactly is a constraint ? Example ?
         * How do pre and post conditions work for a method like clear()
         * @TODO
         * Implement Contracts + Constraints
         * Implement Java Comments on Constructors + Contracts
         */

        //Add the code to print the queue. After the code is finished,
        //the queue should still contain all its values in order
    }
}

