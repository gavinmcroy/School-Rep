package com.company;

public class Cuboid extends Rectangle {


    private double height = 0;

    public Cuboid(double length, double width, double height) {
        super(length, width);
        if (height > 0) {
            this.height = height;
        }
    }

    public double getHeight() {
        return this.height;
    }

    public double getVolume() {
        return getArea() * this.height;
    }
}
