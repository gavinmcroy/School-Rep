package com.company;

public class Main {

    public static void main(String[] args) {

        //---First Scenario
        int highScore = calculateScore(true, 5_000, 5, 100);
        System.out.println(highScore);

        //---Second Scenario
        highScore = calculateScore(true, 5_000, 5, 100)
        System.out.println(highScore);
    }

    public static int calculateScore(boolean gameOver, int score, int levelCompleted, int bonus) {
        if (gameOver) {
            int finalScore = score + (levelCompleted * bonus);
            return finalScore;
        }
        return -1;
    }
}

