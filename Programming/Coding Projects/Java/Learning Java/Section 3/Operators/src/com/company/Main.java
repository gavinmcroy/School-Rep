package com.company;

public class Main {

    public static void main(String[] args) {
        int result = 1 + 2;
        int previous = result;
        result = result - 1;
        System.out.println("1 + 2 = " + previous);
        System.out.println("3 - 1 = " + result);

        previous = result;
        result = result * 10;
        System.out.println(previous + " * 10 = " + result);

        previous = result;
        result = result / 5;
        System.out.println(previous + " / 5 = " + result);

        previous = result;
        result = result % 3;
        System.out.println(previous + " % 3 = " + result);

        int topScore = 100;
        if (topScore == 100)
            System.out.println("You got the high score! ");
        if (topScore >= 60 && topScore <= 100)
            System.out.println("Functioning");

        if (topScore >= 100 || topScore <= 90) {
            System.out.println("Dont know what to write");
        }
        //---Boolean Trip up
        boolean isCar = false;
        if (isCar = true)
            System.out.println("this isnt supposed to happen! ");

        if (isCar) {
            isCar = false;
            System.out.println("will this output..?");
        }
        //--Ternary Operator
        //---If car is true , was car is true , else was car is false
        boolean wasCar = isCar ? true : false;
        System.out.println(wasCar);

        double val1 = 20;
        double val2 = 80;
        double total = (val1+val2)*25;
        total%=40;
        if(total<=20){
            System.out.println("Value is over limit ");
        }



    }
}
