package cpsc2150.MyQueue;

import java.util.Scanner;

public class QueueApp {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String userAnswer;
        int userChoice = 0;
        IQueue q = null;

        System.out.println("Do you want an array (Type array) or list implementation? (Type list) ");
        userAnswer = scanner.nextLine();
        userAnswer = userAnswer.toLowerCase();
        if (userAnswer.equals("list")) {
            q = new ListQueue();
        } else if (userAnswer.equals("array")) {
            q = new ArrayQueue();
        } else {
            System.out.println("Invalid input");
            System.exit(1);
        }

        while (true) {
            printMenu();
            if (scanner.hasNextInt()) {
                userChoice = scanner.nextInt();
            } else {
                System.out.println("Invalid character");
                System.exit(1);
            }
            switch (userChoice) {
                /* Add to queue */
                case 1:
                    System.out.println("What number to add to the queue");
                    int x = scanner.nextInt();
                    q.enqueue(x);
                    break;
                /* Next number in the queue */
                case 2:
                    if (q.length() == 0) {
                        System.out.println("Queue is empty!");
                        break;
                    }
                    System.out.println("Next number in the queue is " + q.get(2));
                    break;
                /* Peek at first value in the queue */
                case 3:
                    if (q.length() == 0) {
                        System.out.println("Queue is empty!");
                        break;
                    }
                    System.out.println("Peek is " + q.peek());
                    break;
                /* Peek at the last value in the queue */
                case 4:
                    if (q.length() == 0) {
                        System.out.println("Queue is empty!");
                        break;
                    }
                    System.out.println("Peek at end " + q.endOfQueue());
                    break;
                /*TODO (Does not insert properly on empty list) Insert into a position in the queue */
                case 5:
                    System.out.println("What number to add to the queue? ");
                    int valToAdd = scanner.nextInt();
                    int positionToEnter;
                    while (true) {
                        System.out.println("What position to insert in? ");
                        positionToEnter = scanner.nextInt();
                        if (positionToEnter > q.length() || positionToEnter < 0) {
                            break;
                        } else {
                            System.out.println("Enter valid position");
                        }
                    }
                    q.insert(valToAdd, positionToEnter);
                    break;
                /* TODO Peek at a value at any position in the queue */
                case 6:
                    if (q.length() == 0) {
                        System.out.println("Queue is empty!");
                        break;
                    }
                    int positionToGet;
                    while (true) {
                        System.out.println("What position do you want from the queue");
                        positionToGet = scanner.nextInt();
                        if (positionToGet > q.length() || positionToGet < 0) {
                            break;
                        }else{
                            System.out.println("Enter valid position");
                        }
                    }
                    System.out.println("Value at position "+positionToGet+" is "+q.get(positionToGet));

                    break;
                /* TODO Remove a value from any position in the queue and return it */
                case 7:
                    if (q.length() == 0) {
                        System.out.println("Queue is empty!");
                        break;
                    }
                    int positionToGet;
                    while (true) {
                        System.out.println("What position do you want from the queue");
                        positionToGet = scanner.nextInt();
                        if (positionToGet > q.length() || positionToGet < 0) {
                            break;
                        }else{
                            System.out.println("Enter valid position");
                        }
                    }
                    break;
                /* Exit */
                case 8:
                    System.out.println("Exiting...");
                    System.exit(1);
                    break;
                default:
            }
            System.out.println("Queue is: \n" + q.toString());
        }
    }

    public static void printMenu() {
        System.out.println("Select an option\n" +
                "1. Add to the queue\n" +
                "2. Get the next number from the queue\n" +
                "3. Peek at the first value in the queue\n" +
                "4. Peek at the last value in the queue\n" +
                "5. Insert into a position in the queue\n" +
                "6. Peek at a value in any position in the queue\n" +
                "7. Remove a value from any position in the queue and return it\n" +
                "8. Exit\n");
    }

    /**
     * TODO:
     * Finish Implementation of ToString();
     * Finish Implementation of main()
     * Finish new contract for new implemented methods inside of IQueue
     *
     */
}

