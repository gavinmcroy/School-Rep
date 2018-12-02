package com.company;

public class Main {

    public static void main(String[] args) {

        int score = calculateHighScorePosition(1000);
        displayHighScorePosition("Gavin",score);

        score = calculateHighScorePosition(900);
        displayHighScorePosition("Gavin",score);

        score = calculateHighScorePosition(400);
        displayHighScorePosition("Gavin",score);

        score = calculateHighScorePosition(50);
        displayHighScorePosition("Gavin",score);


    }

    public static void displayHighScorePosition(String playerName, int tablePosition){
        System.out.println(playerName+" managed to get into position "+tablePosition);
    }

    public static int calculateHighScorePosition(int playerScore){
        if(playerScore>=1000){
            return 1;
        }else if(playerScore>=500){
            return 2;
        }else if(playerScore>=100){
            return 3;
        }
        return 4;
    }
}
