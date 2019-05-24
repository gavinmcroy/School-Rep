package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
//        ArrayList<Integer> items = new ArrayList<>();
//        items.add(1);
//        items.add(2);
//        items.add(3);
//        items.add(4);
//        items.add(5);
//        printDoubled(items);

        FootBallPlayer joe = new FootBallPlayer("Joe");
        BaseballPlayer pat = new BaseballPlayer("Pat");
        SoccerPlayer beckham = new SoccerPlayer("Beckham");

        Team<FootBallPlayer> bigGav = new Team<>("Big gav");
        bigGav.addPlayer(joe);
//        bigGav.addPlayer(pat);
//        bigGav.addPlayer(beckham);
        Team<BaseballPlayer> baseballPlayerTeam = new Team<>("ChicagoCubs");
        baseballPlayerTeam.addPlayer(pat);

        Team<SoccerPlayer> soccerPlayerTeam = new Team<>("NotASport");
        soccerPlayerTeam.addPlayer(beckham);

        //---Generics limits the input by only using team members that extend Player
        //---The diamond operator as well limits the Input by locking the type to what ever is inputed
        //---Example being if its string you cant add a int
        //---Generics allows it so you can only input certain objects instead of any object
        Team<SoccerPlayer> stringTeam = new Team<>("Name");
//        stringTeam.addPlayer("Pat");

        System.out.println("Ranking: ");
        System.out.println(baseballPlayerTeam.ranking());



    }

    private static void printDoubled(ArrayList<Integer> n) {
        for (int i : n) {
            System.out.println(i * 2);
        }
    }

}
