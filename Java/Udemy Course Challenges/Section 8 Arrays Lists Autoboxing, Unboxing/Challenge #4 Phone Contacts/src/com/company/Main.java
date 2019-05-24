package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    private static MobilePhone phone = new MobilePhone();

    public static void main(String[] args) {
        mainMenu();
        userInput();
        scanner.close();
        //---Bug in update contacts can update contacts and have two of same information
    }

    private static void mainMenu() {
        System.out.println("Select one of the Following Options");
        System.out.println("1. Reprint Instructions");
        System.out.println("2. Add a contact");
        System.out.println("3. Print contacts");
        System.out.println("4. Update current contact");
        System.out.println("5. Remove contact");
        System.out.println("6. Search for contact");
        System.out.println("7. Quit Application");
    }

    private static void userInput() {
        boolean quit = false;
        while (!quit) {
            int userChoice = scanner.nextInt();
            scanner.nextLine();
            switch (userChoice) {
                case 1:
                    mainMenu();
                    break;
                case 2:
                    phone.addContact();
                    break;
                case 3:
                    phone.printContact();
                    break;
                case 4:
                    phone.updateCurrentContact();
                    break;
                case 5:
                    phone.removeContact();
                    break;
                case 6:
                    phone.searchContact();
                    break;
                case 7:
                    System.out.println("Closing application");
                    quit = true;
                    break;
                default:
                    System.out.println("No option was selected try again");
            }
        }
    }
}

