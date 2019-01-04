package com.company;

public class Main {

    public static void main(String[] args) {
        whileLoop(1,20);
        int count = 1;
        while (count != 5) {
            System.out.println("Count value is " + count);
            count++;
        }
        System.out.println("*********************");
        for (count = 1; count != 5; count++) {
            System.out.println("Count value is " + count);
        }
        System.out.println("*********************");
        count = 1;
        while (true) {
            if (count == 5) {
                break;
            }
            System.out.println("Count value is " + count);
            count++;
        }
        System.out.println("*********************");
        count = 1;
        do {
            System.out.println("Count value is " + count);
            count++;
        } while (count != 5);
    }

    public static boolean isEven(int evenOrNot) {
        if (evenOrNot % 2 == 0) {
            return true;
        } else {
            return false;
        }
    }

    public static void whileLoop(int number, int finishNumber) {
        int evenNumber = 0;
        int evenNumberTotal =0;
        while (number <= finishNumber) {
            number++;
            if(!isEven(number)){
                continue;
            }
            if(evenNumber==5){
                break;
            }
            evenNumberTotal+=number;
            evenNumber++;
            System.out.println("Even number! "+number);
        }
        System.out.println(evenNumberTotal);
    }
}