package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println("Sum is: "+sumDigits(125));
        System.out.println(betterSumDigits(125));
    }

    public static int sumDigits(int number) {
        int sum =0;
        int digit = 1;
        if(number>=10){
            for(int i = 10000; i>=1;i/=10){
                digit = number/i;
                number=number-(digit*i);
                sum+=digit;
            }
            return sum;
        }else{
            System.out.println("Invalid Value");
            return -1;
        }
    }
    public static int betterSumDigits(int number){
        if(number>=10){
            int sum = 0;
            while(number>=1){
                int digit = number % 10;
                sum+=digit;
                number/=10;
            }
            return sum;
        }else{
            return -1;
        }
    }
}
