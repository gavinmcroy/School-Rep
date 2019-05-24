package com.company;

public class Team implements Comparable<Team> {

    private String name;
    private int win = 0;
    private int lost = 0;
    private int tie = 0;
    private int totalScore = 0;

    public Team(String name) {
        this.name = name;
    }

    public void setScore(int win, int lost, int tie) {
        this.win = win;
        this.lost = lost;
        this.tie = tie;
    }

    public int calculateScore() {
        this.totalScore = (this.win * 2) + this.tie;
        return this.totalScore;
    }

    public String getName() {
        return name;
    }

    public int getWin() {
        return win;
    }

    public int getLost() {
        return lost;
    }

    public int getTie() {
        return tie;
    }


    @Override
    public int compareTo(Team team) {
        if (this.calculateScore() > team.calculateScore()) {
            return -1;
        } else if (this.calculateScore() == team.calculateScore()) {
            return 0;
        } else {
            return 1;
        }
    }

    @Override
    public String toString() {
        return "Team{" +
                "name='" + name + '\'' +
                ", win=" + win +
                ", lost=" + lost +
                ", tie=" + tie +
                ", totalScore=" + totalScore +
                '}';
    }
}
