package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int min = 0;
        int max = 0;
        boolean first = true;
        while (true) {
            System.out.println("Enter a number");
            boolean hasInt = scanner.hasNextInt();
            if (!hasInt) {
                System.out.println("Invalid");
                System.out.println("Highest: " + max + " Lowest: " + min);
                break;
            }
            if (hasInt) {
                int input = scanner.nextInt();
                if(first){
                    min = input;
                    max = input;
                    first=false;
                }
                if (input > max) {
                    max = input;
                    System.out.println("New Max! " + max);
                } else if (input < min) {
                    min = input;
                    System.out.println("New min! " + min);
                }

            } else {
                break;
            }
        }
        scanner.close();
    }
}
