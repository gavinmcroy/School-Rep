package com.company;

import java.util.Scanner;

public class Calculator {

    private Scanner scanner = new Scanner(System.in);
    private double totalNumber = 0;

    public Calculator() {
        mainApplication();
    }

    private void mainApplication() {
        mainMenu();
        determineUserChoice(readUserChoice());
    }

    private void mainMenu() {
        System.out.println("Choose one of the following Options\n" +
                "1. Add\n" +
                "2. Subtract\n" +
                "3. Multiply\n" +
                "4. Divide\n" +
                "5. Quit");
    }

    private int readUserChoice() {
        boolean hasInt = scanner.hasNextInt();
        if (hasInt) {
            return scanner.nextInt();
        } else {
            System.out.println("Enter a integer");
            return -1;
        }
    }

    private void determineUserChoice(int userChoice) {
        switch (userChoice) {
            case 1:
                add(recordNumberInput());
                break;
            default:
                System.out.println("Working!");
        }
    }

    private void add(double numberToAdd) {
        //---Adds what ever numbers user enters together until they want to stop
        //---Keeps track of number until user clears
        System.out.println(numberToAdd);
        this.totalNumber += numberToAdd;
    }

    private void subtract() {

    }

    private void multiply() {

    }

    private void divide() {

    }

    private double recordNumberInput() {
        System.out.println("Enter the desired number ");
        boolean hasDouble = scanner.hasNextDouble();
        if (hasDouble) {
            return scanner.nextDouble();
        } else {
            System.out.println("Enter a number please");
            return -1;
        }
    }

}
