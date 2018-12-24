package com.company;

public class Main {

    public static final double VAL_OF_PI = 3.141592;

    public static void main(String[] args) {
        System.out.println(areaCalculator(5));
        System.out.println(areaCalculator(5,5));
    }

    public static double areaCalculator(double radius) {
        if (radius >= 0) {
            return (radius * radius) * VAL_OF_PI;
        } else {
            return -1;
        }
    }

    public static double areaCalculator(double x, double y) {
        if (x >= 0 && y >= 0) {
            return x * y;
        } else {
            return -1;
        }
    }
}
