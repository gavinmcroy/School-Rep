package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        sum();
    }

    public static void sum() {
        Scanner scanner = new Scanner(System.in);
        int amount = 1;
        int sum = 0;
        while (amount != 11) {
            System.out.println("Enter number #" + amount);
            boolean hasNextInt = scanner.hasNextInt();

            if (hasNextInt) {
                sum += scanner.nextInt();
                amount++;
            } else {
                System.out.println("Invalid Input");
            }
            scanner.nextLine();
        }
        System.out.println("Sum = "+sum);
        scanner.close();
    }
}
