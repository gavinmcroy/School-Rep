package com.company;

public class Main {
    //1221 1001 707
    public static void main(String[] args) {
        System.out.println(isPalindrome(-1101));
    }
    public static boolean isPalindrome(int number){
        int reverse = 0;
        int num = number;
        while(num!=0){
            int lastDigit = num%10;
            reverse=reverse*10 +lastDigit;
            num/=10;
            System.out.println(lastDigit);
        }
        if(reverse==number){
            return true;
        }else {
            return false;
        }
    }
}
