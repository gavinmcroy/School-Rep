package com.company;

public class Main {

    public static void main(String[] args) {
        //---Polymorphism
        for (int i = 1; i <= 11; i++) {
            Movie movie = randomMovie();
            System.out.println("Movie # " + i + " :" + movie.getMovieName() + "\n" +
                    "Plot: " + movie.plot() + '\n');
        }
    }

    public static Movie randomMovie() {
        int randomNumber = (int) (Math.random() * 5) + 1;
        System.out.println("Random number gen: " + randomNumber);
        switch (randomNumber) {
            case 1:
                return new Jaws();
            case 2:
                return new Independance();
            case 3:
                return new MazeRunner();
            case 4:
                return new StarWars();
            case 5:
                //---Has no Plot method java defaults to Super class Movie Polymorphism
                return new ForgettableMovie();
            default:
                return null;
        }
    }
}
