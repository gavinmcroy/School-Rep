package com.company;

public class Main {

    public static void main(String[] args) {
	    boolean leap = isLeapYear(2_000);
        System.out.println(leap);
    }
    public static boolean isLeapYear(int year){
        if(year>=1 && year<=9999){
            if((year%4==0 && year%100!=0)|| year%400==0)
            {
                return true;
            }
            return false ;
        }else{
            return false;
        }
    }
}
