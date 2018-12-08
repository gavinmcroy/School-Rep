package com.company;

public class Main {

    public static void main(String[] args) {
        printYearsAndDays(525600);
    }

    public static void printYearsAndDays(long minutes) {
        if (minutes >= 0) {
            long hour = minutes / 60;
            long day = hour/24;
            long year = day/365;
            long dayRemaining = day%365;
            System.out.println(minutes+" min"+" = "+year+" y and "+dayRemaining+" d");
        } else {
            System.out.println("Invalid Value");
        }
    }

}
