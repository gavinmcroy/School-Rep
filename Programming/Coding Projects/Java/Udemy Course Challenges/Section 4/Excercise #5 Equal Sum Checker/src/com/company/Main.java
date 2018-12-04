package com.company;

public class Main {

    public static void main(String[] args) {
	    boolean isEqual = hasEqualSum(1,2,3);
        System.out.println(isEqual);
    }
    public static boolean hasEqualSum (int val,int val2,int val3){
        if(val+val2==val3){
            return true;
        }else{
            return false;
        }
    }
}
