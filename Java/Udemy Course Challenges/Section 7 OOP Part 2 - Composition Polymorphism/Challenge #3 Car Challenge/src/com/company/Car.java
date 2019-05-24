package com.company;

public class Car {

    private int numberOfCylinders;
    private int numberOfWheels;
    private double engineSize;
    private int carYear;

    public Car(int numberOfCylinders, int numberOfWheels, int engineSize, int carYear) {
        this.numberOfCylinders = numberOfCylinders;
        this.numberOfWheels = numberOfWheels;
        this.engineSize = engineSize;
        this.carYear = carYear;
    }

    public void startEngine() {
        System.out.println("Car --> No Engine");
    }

    public void accelerate() {
        System.out.println("Car --> No Accelerating");
    }

    public void braking() {
        System.out.println("Car --> No Braking");
    }

    public int getNumberOfCylinders() {
        return numberOfCylinders;
    }
}
