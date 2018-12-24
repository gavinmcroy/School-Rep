package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(isPerfectNumber(28));
    }
    public static boolean isPerfectNumber(int number){
        if(number>=1){
            int factor = 0;
            int perfectNumber=0;
            for(int i = 1; i<number; i++){
                factor = number % i;
                if(factor==0){
                    perfectNumber+=i;
                }
            }
            if(perfectNumber==number){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
}
