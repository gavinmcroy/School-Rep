package com.company;

public class Mclaren extends Car {

    private int horsePower;
    private int weight;

    public Mclaren( int engineSize, int horsePower, int weight) {
        super(10,4, engineSize, 2018);
        this.horsePower = horsePower;
        this.weight = weight;
    }

    @Override
    public void startEngine() {
        System.out.println("Mclaren is cranking");
    }

    @Override
    public void accelerate() {
        System.out.println("Mclaren is accelerating");
    }

    @Override
    public void braking() {
        System.out.println("Mclaren is braking");
    }
}
