package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(canPack(1, 0, 4));
    }
    public static boolean canPack (int bigCount,     int smallCount, int goal){
        if(bigCount < 0 || smallCount < 0 || goal <= 0 || (bigCount * 5 + smallCount < goal)){
            return false;
        }
        //If any of the parameters is negative or goal is greater than available quantity of flour, return false.

        return (goal % 5 <= smallCount);
        //Number of kilos must be smaller or equal to remainder of goal/bigCount value (5).
    }
}
