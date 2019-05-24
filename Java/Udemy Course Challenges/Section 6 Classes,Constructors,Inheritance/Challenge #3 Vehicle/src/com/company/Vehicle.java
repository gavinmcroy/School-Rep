package com.company;

public class Vehicle {

    private boolean hasEngine;
    private boolean isElectric;
    private boolean hasPowerSteering;
    private boolean hasHeadLights;
    private boolean hasBlinker;

    public Vehicle(boolean hasEngine, boolean isElectric, boolean hasPowerSteering, boolean hasHeadLights,
                   boolean hasBlinker) {
        this.hasEngine = hasEngine;
        this.isElectric = isElectric;
        this.hasPowerSteering = hasPowerSteering;
        this.hasHeadLights = hasHeadLights;
        this.hasBlinker = hasBlinker;
    }

}
