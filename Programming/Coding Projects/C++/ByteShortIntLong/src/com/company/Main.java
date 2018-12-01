package com.company;

public class Main {

    public static void main(String[] args) {
        long myLongValue = 10L;
        //---Smallest Number for a int;
        int minValue = -2_147_483_648;
        int maxValue = 2_147_483_647;
        //---Range for Byte(127,-128)
        byte myByte = -128;
        //--Casting Data Type. Java Default Converts it to int
        byte myByteTotal = (byte) (myByte/2);
        //---Range for Byte(32_768,32_767)
        short myShort = 32_767;
	    System.out.println("Hello World! ");
        System.out.println(minValue+" "+maxValue);
        System.out.println(myLongValue);
        System.out.println(myByteTotal+" "+myShort);
        byte smallData = 10;
        short shortData = 50;
        int normalData = 100;
        long bigData = 50_000L +10L*(smallData+normalData+shortData);
        System.out.println(bigData);
    }
}
