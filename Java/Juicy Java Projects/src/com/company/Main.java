package com.company;

import java.util.Scanner;

public class Main {

    private static String gav = "My name";
    private static String number = "4";
    private static int  i= 4;
    private static float l =4.4f;

    static boolean isName = true;
    private static Scanner scanner = new Scanner(System.in);


    public static void main(String[] args) {
        test();
        loop();
        System.out.println("Enter a number");
        int num = scanner.nextInt();
        System.out.println(num*num);
        System.out.println(add(1,2));
    }

    public static void test(){
        if(isName){
            System.out.println("Hello world");
        }
    }

    public static void loop(){
        for(int i = 0; i<gav.length();i++){
            System.out.println("Gav");
        }
    }

    public static int add(int a , int b){
        return a+b;
    }

    public static int switchTest(char input){
        switch(input){
            case 'A':
                System.out.println("This is option A");
            case 'B':
                System.out.println("this is option B");
        }
    }
}
