package com.company;

public class Fish extends Animal {

    private int eyes;
    private int gills;
    private int fins;
    private String color;

    public Fish(int size, int weight, String name, int eyes, int gills, int fins, String color) {
        super(1, 1, size, weight, name);
        this.eyes = eyes;
        this.gills = gills;
        this.fins = fins;
        this.color = color;
    }

    private void rest() {

    }

    private void moveMuscle() {

    }

    private void moveBackFin() {

    }

    private void swim(int speed) {
        moveMuscle();
        moveBackFin();
        super.move(speed);
    }
}
