package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int[] array = readIntegers(5);
        System.out.println(findMinElement(array));
    }

    private static int[] readIntegers(int count) {
        int[] array = new int[count];
        for (int i = 0; i < count; i++) {
            System.out.println("Enter a number into element " + i);
            array[i] = scanner.nextInt();
            scanner.nextLine();
        }
        scanner.close();
        return array;
    }

    private static int findMinElement(int[] array) {
        int minVal = Integer.MAX_VALUE;
        for (int i = 0; i < array.length; i++) {
            if (array[i] < minVal) {
                minVal = array[i];
            }
        }
        return minVal;
    }
}
