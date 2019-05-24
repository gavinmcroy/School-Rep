package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int myIntValue = 10;
        int secondIntValue = myIntValue;

        System.out.println("My int Value = " + myIntValue);
        System.out.println("My second int Value = " + secondIntValue);

        secondIntValue++;

        System.out.println("My int Value = " + myIntValue);
        System.out.println("My second int Value = " + secondIntValue);

        int[] myIntArrays = new int[5];
        //---Second reference to myIntArrays
        int[] mySecondArray = myIntArrays;

        System.out.println("My int array = " + Arrays.toString(myIntArrays));
        System.out.println("Second int array = " + Arrays.toString(mySecondArray));

        mySecondArray[0] = 1;

        System.out.println("*My int array = " + Arrays.toString(myIntArrays));
        System.out.println("*Second int array = " + Arrays.toString(mySecondArray));

        modifyArray(myIntArrays);

        System.out.println("After Modify My int array = " + Arrays.toString(myIntArrays));
        System.out.println("After Modify Second int array = " + Arrays.toString(mySecondArray));
    }
    private static void modifyArray(int[] array){
        array[0]=2;
        //---Dereference
        array = new int[] {1,2,3,4};
    }
}
