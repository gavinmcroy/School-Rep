package com.company;

public class Main {

    public static void main(String[] args) {
        int newScore = calcScore("Gavin", 500);
        System.out.println(newScore);
        calcScore(50);
        calcScore();
        double mainCalcValue = calcFeetAndInchesToCentimeters(1,12);
        System.out.println(mainCalcValue);
        double calcValue = calcFeetAndInchesToCentimeters(55);
        System.out.println(calcValue);
    }

    public static int calcScore(String playerName, int score) {
        System.out.println("Player " + playerName + " scored " + score + " points");
        return score * 1000;
    }

    public static int calcScore(int score) {
        System.out.println(" scored " + score + " points");
        return score * 1000;
    }

    public static int calcScore() {
        System.out.println(" no points scored ");
        return 0;
    }

    public static double calcFeetAndInchesToCentimeters(double feet, double inches) {
        double centimeters;
        if (feet >= 0) {
            if (inches >= 0 && inches < 12) {
                centimeters = (feet * 12 * 2.54) + (inches * 2.54);
                return centimeters;
            } else if(inches==12) {
                feet++;
                centimeters = (feet * 12) * 2.54;
                return centimeters;
            }else{
                System.out.println("Invalid Input");
                return -1;
            }
        } else {
            System.out.println("Invalid Input");
            return -1;
        }
    }

    public static double calcFeetAndInchesToCentimeters(double inches) {
        if (inches >= 0) {
            double inch = inches % 12;
            inches -= inch;
            double foot = inches / 12;
            double conversion = calcFeetAndInchesToCentimeters(foot, inch);
            return conversion;
        } else {
            System.out.println("Invalid input");
            return -1;
        }
    }
}
