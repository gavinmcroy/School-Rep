package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
//	    Integer integer = new Integer(54);
        ArrayList<Integer> intList = new ArrayList<>();

        for(int i = 0; i<=10;i++){
            intList.add(i);
        }
        for(int i = 0; i<=10;i++){
            System.out.println(intList.get(i).intValue());
        }
        Integer myIntVal = 56;
        int myInt = myIntVal;

        ArrayList<Double> myDoubles = new ArrayList<>();
        for(double dbl = 0.0; dbl<=10.0;dbl+=.5){
            myDoubles.add(dbl);
        }
        for(int i = 0; i<myDoubles.size();i++){
            System.out.println(myDoubles.get(i).doubleValue());
        }
    }
}
