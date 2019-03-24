package com.company;

public class Main {

    public static void main(String[] args) {
        LeagueList<FootBallTeam> leagueList = new LeagueList<>();
        FootBallTeam footBallTeam = new FootBallTeam("Gav");
        FootBallTeam footBallTeam1 = new FootBallTeam("BIG G");
        FootBallTeam footBallTeam2 = new FootBallTeam("Skinny G");
//        SoccerTeam soccerTeam = new SoccerTeam("Booo");
        footBallTeam1.setScore(1, 1, 1);
        leagueList.addTeam(footBallTeam1);
        footBallTeam.setScore(10, 1, 0);
        footBallTeam2.setScore(5,5,5);
        leagueList.addTeam(footBallTeam);
        leagueList.addTeam(footBallTeam2);
        footBallTeam.calculateScore();
        leagueList.leagueRanking();
        leagueList.printStandings();


    }
}
