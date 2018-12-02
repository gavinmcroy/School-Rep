package com.company;

public class Main {

    public static void main(String[] args) {

        boolean barkCheck = bark(true,22);
        System.out.println(barkCheck);
    }

    public static boolean bark (boolean barking,int hourOfDay){
        if(hourOfDay>=0 && hourOfDay<=23){
            if(barking && (hourOfDay<8 || hourOfDay>22 )){
                return true;
            }
            return false;
        }
        else{
            return false;
        }
    }
}
