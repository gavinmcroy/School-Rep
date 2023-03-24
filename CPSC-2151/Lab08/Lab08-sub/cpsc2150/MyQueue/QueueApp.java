package cpsc2150.MyQueue;

import java.util.*;
import java.io.*;

public class QueueApp<T> {

    public static void main(String [] args)
    {
        IQueue q = null;

        int queueChoice = 0;
        while (queueChoice == 0){
            System.out.println("Do you want a list or an array? Type 1 for list or 2 for array. ");

            Scanner scanner = new Scanner(System.in);
            queueChoice = scanner.nextInt();

            if (queueChoice==1){
               q = new ListQueue();
            }
            else if (queueChoice==2){
                q = new ArrayQueue();
            }
            else {
                System.out.println("Invalid type. Try again.");
                queueChoice = 0;
            }
        }

        int menuChoice = 1;
        while(menuChoice > 0){
            System.out.println("Select an option:");
            System.out.println("1. Add to the Queue");
            System.out.println("2. Get next Integer from the Queue");
            System.out.println("3. Peek at the front of the Queue");
            System.out.println("4. Peek at the end of the Queue");
            System.out.println("5. Insert in the Queue");
            System.out.println("6. Get a position in the Queue");
            System.out.println("7. Remove from a position in the Queue");
            System.out.println("8. Quit");

            Scanner scanner = new Scanner(System.in);
            menuChoice = scanner.nextInt();

            //switch(menuChoice){
            if (menuChoice==1) {
                if (q.length() == q.MAX_LENGTH) {
                    System.out.println("Queue is full!");

                } else {
                    System.out.println("What number to add to the Queue?");
                    Integer newNum = scanner.nextInt();
                    q.enqueue(newNum);
                }
            }

            else if (menuChoice==2) {
                if (q.length() == 0) {
                    System.out.println("Queue is empty!");

                } else {
                    System.out.println("Next number is " + q.dequeue());

                }
            }

            else if (menuChoice==3) {
                if (q.length() == 0) {
                    System.out.println("Queue is empty!");

                } else {
                    System.out.println("Peek: " + q.peek());
                }
            }

            else if (menuChoice==4) {
                if (q.length() == 0) {
                    System.out.println("Queue is empty!");

                } else {
                    System.out.println("Peek at end: " + q.endOfQueue());
                }
            }

            else if (menuChoice==5) {
                if (q.length() == q.MAX_LENGTH) {
                    System.out.println("Queue is full!");
                } else {
                    System.out.println("What number to add to the Queue?");
                    Integer newNum = scanner.nextInt();
                    int pos = 0;
                    while (pos <= 0 || pos > q.length()) {
                        System.out.println("What position to insert in?");
                        pos = scanner.nextInt();
                        if (pos <= 0 || pos > q.length()) {
                            System.out.println("Not a valid position in the Queue!");
                        }
                    }
                    q.insert(newNum, pos);
                }
            }

            else if (menuChoice==6) {
                if (q.length() == 0) {
                    System.out.println("Queue is empty!");
                } else {
                    int pos = 0;
                    while (pos <= 0 || pos > q.length()) {
                        System.out.println("What position to get?");
                        pos = scanner.nextInt();
                        if (pos <= 0 || pos > q.length()) {
                            System.out.println("Not a valid position in the Queue!");
                        }
                    }
                    System.out.println(q.get(pos) + " is at position " + pos + " in the queue");
                }
            }

            else if (menuChoice==7) {
                if (q.length() == 0) {
                    System.out.println("Queue is empty!");
                } else {
                    int pos = 0;
                    while (pos <= 0 || pos > q.length()) {
                        System.out.println("What position to remove from the Queue?");
                        pos = scanner.nextInt();
                        if (pos < 0 || pos > q.length()) {
                            System.out.println("Not a valid position in the Queue!");
                        }
                    }
                    System.out.println(q.remove(pos) + " was at position " + pos + " in the queue");
                }
            }


            else if (menuChoice==8) {
                menuChoice = 0;
                break;
            }

            else {
                System.out.println("Not a valid option!");
                menuChoice = 1;
            }

            System.out.println("Queue is:");
            System.out.println(q.toString());
            System.out.println("\n");

        }

    }

}
