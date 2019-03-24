package com.company;

import java.util.ArrayList;
import java.util.Collections;

public class LeagueList<T extends Team> {

    private ArrayList<T> teamList;

    public LeagueList() {
        this.teamList = new ArrayList<>();
    }

    public void addTeam(T team) {
        teamList.add(team);
    }


    public void leagueRanking() {
        Collections.sort(teamList);
    }

    public void printStandings() {
        for (int i = 0; i < teamList.size(); i++) {
            System.out.println(teamList.get(i));
        }
    }

}
