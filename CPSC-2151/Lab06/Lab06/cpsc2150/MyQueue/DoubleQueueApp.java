package cpsc2150.MyQueue;

import java.util.Scanner;

public class DoubleQueueApp {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int usersImplementationChoice;
        int userChoice = 0;
        IQueue<Double> q = null;

        /* Input for which implementation the user wants */
        System.out.println("Enter 1 for array implementation or 2 for List implementation ");
        usersImplementationChoice = scanner.nextInt();

        /* Make sure valid implementation is selected */
        if (usersImplementationChoice == 1) {
            q = new ArrayQueue<>();
        } else if (usersImplementationChoice == 2) {
            q = new ListQueue<>();
        } else {
            System.out.println("Invalid input");
            System.exit(1);
        }
        /* Make sure a integer was entered */
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
                case 1: {
                    System.out.println("What number to add to the queue");
                    double x = scanner.nextDouble();
                    /* Special case for when queue is full */
                    if (q.length() == IQueue.MAX_LENGTH) {
                        System.out.println("Queue is full");
                        break;
                    }
                    q.enqueue(x);
                    break;
                }
                /* Next number in the queue */
                case 2: {
                    if (isQueueEmpty(q)) {
                        break;
                    } else {
                        System.out.println("Next number in the queue is " + q.get(1));
                        q.remove(1);
                        break;
                    }
                }
                /* Peek at first value in the queue */
                case 3: {
                    if (isQueueEmpty(q)) {
                        break;
                    }

                    System.out.println("Peek is " + q.peek());
                    break;
                }
                /* Peek at the last value in the queue */
                case 4: {
                    if (isQueueEmpty(q)) {
                        break;
                    }
                    System.out.println("Peek at end " + q.endOfQueue());
                    break;
                }
                /* Insert into a position in the queue */
                case 5: {
                    System.out.println("What number to add to the queue? ");
                    double valToAdd = scanner.nextDouble();
                    int position;

                    /* Special case for when queue is full */
                    if (q.length() == IQueue.MAX_LENGTH) {
                        System.out.println("Queue is full");
                        break;
                    }
                    while (true) {
                        System.out.println("What position to insert in?");
                        position = scanner.nextInt();
                        /* Special case for first element */
                        if (q.length() == 0) {
                            q.insert(valToAdd, 1);
                            break;
                        }
                        /* Special case for element one above current size */
                        if (position - 1 == q.length()) {
                            q.enqueue(valToAdd);
                            break;
                        }
                        if (position > q.length() || position < 0) {
                            System.out.println("Not a valid position in the queue! ");
                        } else {
                            q.insert(valToAdd, position);
                            break;
                        }
                    }
                    break;
                }
                /* Peek at a value at any position in the queue */
                case 6: {
                    String message = "What position to get from the Queue?";
                    if (isQueueEmpty(q)) {
                        break;
                    }
                    Integer positionToGet = readDesiredPosition(q, message);
                    System.out.println("Value at position " + positionToGet + " is " + q.get(positionToGet));
                    break;

                }
                /* Remove a value from any position in the queue and return it */
                case 7: {
                    String message = "What position to remove from the Queue?";
                    if (isQueueEmpty(q)) {
                        break;
                    }
                    int pos = readDesiredPosition(q, message);
                    System.out.println(q.get(pos) + " was at the position " + pos + " in the queue");
                    q.remove(pos);
                    break;
                }
                /* Exit */
                case 8:
                    System.out.println("Exiting...");
                    System.exit(1);
                    break;
                default:
                    System.out.println("Not a valid option! ");
                    break;
            }
            System.out.println("Queue is: \n" + q.toString());
        }
    }

    /**
     * Prints a menu with 8 different options that the user can look at. Does not accept input only prints
     * the menu
     *
     * @pre none
     * @post none
     */
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
     * <p>
     * Determines if the queue is empty and prints a message notifying the user if the queue is empty. It also
     * returns true if the queue is empty and false if it is not empty.
     *
     * @param q the queue being checked in order to determine if it is empty or not
     * @return returns true if the queue is empty and false if the queue is not empty
     * @pre q != null
     * @post isQueueEmpty = (q.length == 0)
     */
    public static boolean isQueueEmpty(IQueue<Double> q) {
        if (q.length() == 0) {
            System.out.println("Queue is empty!");
            return true;
        }
        return false;
    }

    /**
     * Reads in a desired position from the user and determines if the position is valid according to the
     * current queue size. If the position is invalid it will loop until the user enters a correct position.
     * If a correct position is entered it will return this position
     *
     * @param q       The queue being checked in order to determine if position is inside the queues bounds
     * @param message A unique message to display such as if you want change what the prompt asks you can pass
     *                any string you desire and the prompt will match the input
     * @return returns a valid position within the bounds of the queue
     * @pre q != null and message != null
     * @post readDesiredPosition() = position
     */
    public static Integer readDesiredPosition(IQueue<Double> q, String message) {
        int position;
        while (true) {
            System.out.println(message);
            position = scanner.nextInt();
            if (position > q.length() || position < 0) {
                System.out.println("Not a valid position in the queue! ");
            } else {
                return position;
            }
        }
    }
}
