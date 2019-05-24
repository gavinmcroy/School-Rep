package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {

        int[] myIntegers = getIntegers(5);
        for(int i = 0;i<myIntegers.length;i++){
            System.out.println("Element "+i+" Typed value was "+myIntegers[i]);
        }

        System.out.println("Average is "+getAverage(myIntegers));

        int[] myIntArray = new int[10];
        int[] mySecondIntArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        myIntArray[5] = 50;
//        for (int i = 0; i < mySecondIntArray.length; i++) {
//            System.out.println(mySecondIntArray[i]);
//        }
//        int[] test = new int[10];
//        for (int i = 0; i < test.length; i++) {
//            test[i] = i * 10;
//            System.out.println(test[i]);
//        }
        printArray(mySecondIntArray);
        scanner.close();
    }

    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static int[] getIntegers(int numbers) {
        System.out.println("Enter " + numbers + " Integer Values\r");
        int[] value = new int[numbers];

        for (int i = 0; i < value.length; i++) {
            value[i] = scanner.nextInt();
        }
        return value;
    }

    public static double getAverage(int[] array){
        int sum = 0;
        for(int i = 0; i<array.length;i++){
            sum+=array[i];
        }
        return (double) sum/(double) array.length;
    }
}
