package com.company;

public class Floor {

    private double width;
    private double length;

    public Floor(double width, double length) {
        if (width >= 0)
            this.width = width;
        if (length >= 0)
            this.length = length;
        else {
            this.length = 0;
            this.width = 0;
        }
    }

    public double getArea() {
        return this.width * this.length;
    }
}
