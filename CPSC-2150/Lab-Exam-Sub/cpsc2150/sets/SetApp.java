package cpsc2150.sets;

import java.util.*;

import static java.lang.System.exit;

public class SetApp {

    private static final int EXIT_CHOICE = 3;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        //Print a menu of options
        printMenu();
        int input = Integer.parseInt(in.nextLine());
        while (input != EXIT_CHOICE) {
            if (input == 1 || input == 2) {
                //Make each set
                if (in == null) {
                    System.out.println("Input is not connected to user. Exitting ");
                    exit(1);
                }
                System.out.println("Make set 1");
                ISet set1 = getSet(in);
                System.out.println("Make set 2");
                ISet set2 = getSet(in);

                //print the sets
                System.out.println("Set 1 is:");
                System.out.println(set1.toString());
                System.out.println("Set 2 is:");
                System.out.println(set2.toString());

                //option 1 is find the union of 2 sets
                if (input == 1) {
                    /* self.getSize() + unionWith.getSize() <= MAX_SIZE */
                    //union the sets together
                    if (set1.getSize() + set2.getSize() <= ISet.MAX_SIZE) {
                        set1.union(set2);

                        //print the union
                        System.out.println("The union is:");
                        System.out.println(set1.toString());
                    } else {
                        System.out.println("Set1 + Set2 exceeds the max size of 100 ");
                    }
                }
                //option 2 is find the intersection of 2 sets
                else {
                    //get the intersection
                    set1.intersect(set2);

                    //print the intersection
                    System.out.println("The intersection is:");
                    System.out.println(set1.toString());
                }
            } else {
                System.out.println("That was not an option");
            }

            //print the menu and get the next option
            printMenu();
            input = Integer.parseInt(in.nextLine());
        }
    }

    /**
     * This method will print the options menu
     *
     * @pre none
     * @post [menu will be displayed to user]
     */
    private static void printMenu() {
        System.out.println("\nMake a selection");
        System.out.println("1. Find the UNION of Two Sets");
        System.out.println("2. Find the INTERSECTION of Two Sets");
        System.out.println(EXIT_CHOICE + ". Exit");
    }

    /**
     * This method will get the values from a user and build a set
     *
     * @param in a scanner object to use to get data from the user
     * @return a set that the user built
     * @pre in is open and connected to the user
     * @post getSet = [set containing the user provided values]
     */
    private static ISet getSet(Scanner in) {
        ISet s;
        //replace this so the user can choose between ListSet and ArraySet
        System.out.println("Would you like to create a ListSet or ArraySet (enter list or array");
        String userAnswer = in.nextLine();
        userAnswer = userAnswer.toLowerCase();
        if (userAnswer.equals("list")) {
            s = new ListSet<Integer>();
        } else {
            s = new ArraySet<Integer>();
        }

        // add values to the set until user enters "qt" to stop entering values
        System.out.println("Enter a value to add to the set. Enter qt to stop adding to the set");
        String val = in.nextLine();
        while (!val.equals("qt")) {
            //we can assume if they did not enter "qt", they did enter a number
            int addVal = Integer.parseInt(val);

            //add the value to our set
            //!contains(val) and size < MAX_SIZE
            if (!s.contains(addVal) && s.getSize() < ISet.MAX_SIZE) {
                s.add(addVal);
            } else {
                System.out.println("Set exceeds max size or contains a duplicate ");
            }

            //get the next value before looping
            System.out.println("Enter a value to add to the set. Enter qt to stop adding to the set");
            val = in.nextLine();
        }

        //we have filled our set, so we can return it
        return s;
    }
}