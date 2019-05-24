package com.company;

public class StarWars extends Movie {

    public StarWars() {
        super("starwars");
    }

    @Override
    public String plot() {
        return "Lots of shooting and universe battles";
    }
}
