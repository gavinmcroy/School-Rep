package com.company;

public class Car extends Vehicle {

    private int totalGear;
    private boolean has4WD;
    private boolean isLeather;
    private boolean hasOverDrive;

    public Car(boolean hasEngine, boolean isElectric, boolean hasPowerSteering, boolean hasHeadLights,
               boolean hasBlinker, int totalGear, boolean has4WD, boolean isLeather, boolean hasOverDrive) {
        super(hasEngine, isElectric, hasPowerSteering, hasHeadLights, hasBlinker);
        this.totalGear = totalGear;
        this.has4WD = has4WD;
        this.isLeather = isLeather;
        this.hasOverDrive = hasOverDrive;
    }

    public void brand(String brand) {
        brand.toLowerCase();
        if (brand.equals("ford")) {
            System.out.println("Your vehicle is junk");
        } else if (brand.equals("mercedes")) {
            System.out.println("Your vehicle is getting stolen");
        } else if (brand.equals("lamborghini")) {
            System.out.println("No one cares your rich");
        } else {
            System.out.println("Your car is trash");
        }
    }
}
