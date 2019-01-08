package com.company;

public class Movie {

    private String movieName;

    public Movie(String movieName) {
        this.movieName = movieName;
    }

    public String plot() {
        return "No Plot here";
    }

    public String getMovieName() {
        return movieName;
    }
}
