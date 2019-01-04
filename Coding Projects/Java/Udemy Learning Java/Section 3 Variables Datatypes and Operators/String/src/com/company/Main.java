package com.company;

public class Main {

    public static void main(String[] args) {
	    String myString = "this is a string";
	    System.out.println(myString);
	    myString = myString +" this is more ! \u00A9";
        System.out.println(myString);
        String numberString = "250.55";
        numberString = numberString+" 25";
        System.out.println(numberString);
        String lastString = "10";
        int num = 20;
        lastString = lastString+num;
        System.out.println(lastString);
    }
}
