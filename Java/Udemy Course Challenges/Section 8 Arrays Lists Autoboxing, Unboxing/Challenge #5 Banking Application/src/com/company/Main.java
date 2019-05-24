package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    private static Bank bank = new Bank();

    public static void main(String[] args) {
        mainMenu();
        bankApp();
    }

    private static void mainMenu() {
        System.out.println("Welcome to the banking application ");
        System.out.println("Option #1: Repeat Menu ");
        System.out.println("Option #2: Add Branch ");
        System.out.println("Option #3: Add Customer to Branch");
        System.out.println("Option #4: Add a transaction to a customer");
        System.out.println("Option #5: Show current customer in a branch");
        System.out.println("Option #6: Show transactions for customer in a branch");
        System.out.println("Option #7: Quit Application");
    }

    private static void bankApp() {
        boolean quit = false;
        while (!quit) {
            boolean hasInt = scanner.hasNextInt();
            if (hasInt) {
                int optionChoice = scanner.nextInt();
                scanner.nextLine();
                switch (optionChoice) {
                    case 1:
                        mainMenu();
                        break;
                    case 2:
                        bank.addBranch();
                        break;
                    case 3:
                        bank.addCustomerToBranch();
                        break;
                    case 4:
                        bank.addTransaction();
                        break;
                    case 5:
                        bank.showCustomersInBranch();
                        break;
                    case 6:
                        bank.showTransactionsForCustomer();
                        break;
                    case 7:
                        quit = true;
                    default:
                        System.out.println("Enter a valid choice");
                        break;
                }
            } else {
                System.out.println("Enter a integer input please");
                scanner.nextLine();
            }
        }
        scanner.close();
    }
}
