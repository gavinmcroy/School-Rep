package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(sumOdd(1,10));
    }
    public static boolean isOdd (int number){
        if(number>=0){
            if(number%2==1){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
    public static int sumOdd(int start , int end){
        int sum = 0;
        if(end>=start && end>=0 && start>=0){
            for(;start<=end;start++){
                if(isOdd(start)){
                    System.out.println(start);
                    sum+=start;
                }
            }
            return sum;
        }else{
            return -1;
        }
    }
}
