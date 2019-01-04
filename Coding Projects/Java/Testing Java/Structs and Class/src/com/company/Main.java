package com.company;

public class Main {

    public static void main(String[] args) {
        weather summerville = new weather(true, true, false, false, true, 80);
        Car ford = new Car("Ford", "F150", 1995, 200_210);
        System.out.println(summerville.isOverCast());
        System.out.println(summerville.isRaining());
        summerville.setSunny(false);
        summerville.setCloudy(false);
        System.out.println(summerville.isCloudy());
        summerville.setTemperature(1000);
        System.out.println(summerville.getTemperature());
        System.out.println(ford.getBrand());
    }
}

