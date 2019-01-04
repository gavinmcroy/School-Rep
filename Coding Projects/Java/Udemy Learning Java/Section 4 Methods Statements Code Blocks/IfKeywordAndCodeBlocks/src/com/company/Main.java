package com.company;

public class Main {

    public static void main(String[] args) {
        boolean gameOver = true;
        int score = 5_000;
        int levelCompleted = 5;
        int bonus = 100;

        if(score<5_000){
            System.out.println("Your Score was lower than 5,000 ");
        }else if(score>5_000){
            System.out.println("Your Score was greater than 5,000 ");
        }else{
            System.out.println("The score is equal to 5,000 ");
        }
        //---First Scenario
        if(gameOver){
            int finalScore = score + (levelCompleted*bonus);
            System.out.println("Your final score was "+finalScore);
        }
        score = 10_000;
        levelCompleted = 8;
        bonus = 200;

        //---Second Scenario
        if(gameOver){
            int finalScore = score + (levelCompleted*bonus);
            System.out.println("Your final score was "+finalScore);
        }
    }
}
