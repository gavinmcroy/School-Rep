package com.company;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter your year of Birth");

        boolean hasNextInt = scanner.hasNextInt();

        if (hasNextInt) {
            int yearOfBirth = scanner.nextInt();
            //---Handle next line Character "ENTER"
            scanner.nextLine();

            System.out.println("Enter your name! ");
            String name = scanner.nextLine();

            int age = 2018 - yearOfBirth;
            if (age >= 0 && age <= 125) {
                System.out.println("Your name is " + name + ", and you are " + age + " years old.");
            } else {
                System.out.println("Invalid Year of Birth");
            }
        }else{
            System.out.println("Enter a valid Number");
        }
        scanner.close();
    }
}
