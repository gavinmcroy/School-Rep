package com.company;

public class TV {

    Resolution resolution;

    public TV(Resolution resolution) {
        this.resolution = resolution;
    }

    public void turnTVOn() {
        System.out.println("TV is on");
    }

    public void turnChannel() {
        System.out.println("Turning Channel");
    }

    public void turnTVOff() {
        System.out.println("Turning TV Off");
    }
}
