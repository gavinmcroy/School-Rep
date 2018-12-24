package com.company;

public class Main {

    public static void main(String[] args) {
	    getGreatestCommonDivisor(18,6);
        System.out.println(getGreatestCommonDivisor(12,30));
    }
    public static int getGreatestCommonDivisor(int first , int second){
        if(first>=10 && second>=10){
            int greatestCommonDivisor=1;
            for(int i = 1; i<=first;i++){
                int commonDivisorFirst = first%i;
                int commonDivisorSecond = second%i;
                if(commonDivisorFirst==0 && commonDivisorSecond==0){
                    greatestCommonDivisor=i;
                }
            }
            return greatestCommonDivisor;
        }else{
            return -1;
        }
    }
}
