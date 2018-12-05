package com.company;

public class Main {

    public static void main(String[] args) {
	    int newScore = calcScore("Gavin",500);
        System.out.println(newScore);
    }
    public static int calcScore (String playerName, int score){
        System.out.println("Player "+playerName+ " scored "+score+" points");
        return score*1000;
    }
    public static int calcScore ( int score){
        System.out.println(" scored "+score+" points");
        return score*1000;
    }
}
