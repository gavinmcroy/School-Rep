package com.company;

public class Main {

    public static void main(String[] args) {
        printFactors(32);
    }
    public static void printFactors(int number){
        if(number>=1){
            for(int i = 1; i<=number;i++){
                int factor = number%i;
                if(factor==0){
                    System.out.print(i+" ");
                }
            }
        }else{
            System.out.println("Invalid Value");
        }
    }
}
