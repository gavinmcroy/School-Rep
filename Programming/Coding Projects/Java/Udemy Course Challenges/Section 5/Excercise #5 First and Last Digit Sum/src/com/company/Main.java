package com.company;

public class Main {
    //---(252 ---> 7)
    public static void main(String[] args) {
        System.out.println(sumFirstAndLastDigit(1000005));
    }

    public static int sumFirstAndLastDigit(int number) {
        if (number < 0) {
            return -1;
        }
        int firstDigit = 0;
        int lastDigit = number;

        while (number >= 1) {
            firstDigit = number % 10;
            lastDigit %= 10;
            number /= 10;
        }
        System.out.println(firstDigit + "    " + lastDigit);
        return lastDigit + firstDigit;
    }
}
