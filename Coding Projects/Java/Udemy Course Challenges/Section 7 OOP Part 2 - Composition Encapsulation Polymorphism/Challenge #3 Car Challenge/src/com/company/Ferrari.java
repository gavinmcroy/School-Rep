package com.company;

public class Ferrari extends Car {

    private int horsePower;
    private int weight;

    public Ferrari(int engineSize, int horsePower, int weight) {
        super(10, 4, engineSize,2018);
        this.horsePower = horsePower;
        this.weight = weight;
    }

    @Override
    public void startEngine() {
        System.out.println("Ferrari is cranking");
    }

    @Override
    public void accelerate() {
        System.out.println("Ferrari is accelerating");
    }

    @Override
    public void braking() {
        System.out.println("Ferrari is braking");
    }
}
