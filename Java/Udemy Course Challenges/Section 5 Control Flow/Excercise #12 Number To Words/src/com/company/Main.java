package com.company;

public class Main {

    public static void main(String[] args) {
        numberToWords(122342);
    }
    public static void numberToWords(int number) {
        if (number < 0)
            System.out.println("Invalid Value");
        else {
            int lastDigit = 0;
            int reverseNumber = reverse(number);
            int differance = (getDigitCount(number)-getDigitCount(reverseNumber));
            while (reverseNumber != 0) {
                lastDigit = reverseNumber % 10;
                switch (lastDigit) {
                    case 0:
                        System.out.println("Zero");
                        break;
                    case 1:
                        System.out.println("One");
                        break;
                    case 2:
                        System.out.println("Two");
                        break;
                    case 3:
                        System.out.println("Three");
                        break;
                    case 4:
                        System.out.println("Four");
                        break;
                    case 5:
                        System.out.println("Five");
                        break;
                    case 6:
                        System.out.println("Six");
                        break;
                    case 7:
                        System.out.println("Seven");
                        break;
                    case 8:
                        System.out.println("Eight");
                        break;
                    case 9:
                        System.out.println("Nine");
                        break;
                }
                reverseNumber = reverseNumber / 10;
            }
            for (int i = 0; i < differance;i++){
                System.out.println("Zero");
            }
        }
    }

    public static int reverse(int number){
        int reverse = 0,lastDigit;
        do {
            lastDigit = number %10;
            reverse = (reverse * 10) + lastDigit;
            number = number / 10;
        }while (number != 0);
        return reverse;
    }

    public static int getDigitCount(int number){
        if(number < 0)
            return -1;
        else {
            int count = 0;
            while (number > 9){
                count++;
                number = number / 10;
            }
            return count+1;
        }
    }
//    //---Converts input number into words (19-->> one nine)
//    public static void numberToWords(int number) {
//        int digit = 1;
//        int digitLength = digitLength(number);
//        if (number >= 0) {
//            while (number >= 1) {
//                digit = number % 10;
//                number /= 10;
//                digitToWords(digit);
//            }
//        } else {
//            System.out.println("Invalid Value");
//        }
//    }
//    //---Input from numberToWords is backwards and must be flipped
//    public static int reverse(int reversal) {
//        return -10;
//    }
//    //---Reversal causes 100-->> to become just 1 and doesn't print as 001
//    public static int digitLength(int input) {
//        if (input >= 0) {
//            int digitLength = 0;
//            while(input>=1){
//                input/=10;
//                digitLength++;
//            }
//            return digitLength;
//        } else {
//            return -1;
//        }
//    }
//
//    //---Digit to Words
//    public static void digitToWords(int digitToWord) {
//        switch (digitToWord) {
//            case 0:
//                System.out.println("Zero");
//                break;
//            case 1:
//                System.out.println("One");
//                break;
//            case 2:
//                System.out.println("Two");
//                break;
//            case 3:
//                System.out.println("Three");
//                break;
//            case 4:
//                System.out.println("Four");
//                break;
//            case 5:
//                System.out.println("Five");
//                break;
//            case 6:
//                System.out.println("Six");
//                break;
//            case 7:
//                System.out.println("Seven");
//                break;
//            case 8:
//                System.out.println("Eight");
//                break;
//            case 9:
//                System.out.println("Nine");
//                break;
//        }
//    }

}
