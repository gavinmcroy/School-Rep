package com.company;

public class Main {

    public static void main(String[] args) {
	    areEqualByThreeDecimalPlaces(2.555,2.333);
    }
    public static boolean areEqualByThreeDecimalPlaces(double compare1,double compare2){

        compare1*=1000;
        compare2*=1000;

        int value1 = (int)compare1;
        int value2 = (int)compare2;

        if(value1==value2){
            return true;
        }else{
            return false;
        }
    }
}
