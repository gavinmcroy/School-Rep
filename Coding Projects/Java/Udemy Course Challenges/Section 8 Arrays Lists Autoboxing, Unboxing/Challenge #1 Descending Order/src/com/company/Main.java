package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int[] array = getIntegers(4);
        sortArray(array);
    }

    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static int[] getIntegers(int size) {
        int array[] = new int[size];
        for (int i = 0; i < array.length; i++) {
            System.out.println("Enter integer at location " + i + "\r");
            array[i] = scanner.nextInt();
        }
        scanner.close();
        return array;
    }

    public static int[] sortArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            for (int j = i; j < array.length; j++) {
                if (array[i] < array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        printArray(array);
        return array;
    }

}
//            if(array[i-1]>array[i] && array[i]>array[i+1]){
//                System.out.println("Array is already Sorted");
//            }