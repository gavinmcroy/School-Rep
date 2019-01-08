package com.company;

public class F150 extends Car {

    private boolean isV8;
    private boolean isLongBed;
    private String color;
    private boolean isEco;

    public F150(boolean hasEngine, boolean isElectric, boolean hasPowerSteering, boolean hasHeadLights,
                boolean hasBlinker, int totalGear, boolean has4WD, boolean isLeather, boolean hasOverDrive,
                boolean isV8, boolean isLongBed, String color, boolean isEco) {
        super(hasEngine, isElectric, hasPowerSteering, hasHeadLights, hasBlinker, totalGear, has4WD, isLeather,
                hasOverDrive);
        this.isV8 = isV8;
        this.isLongBed = isLongBed;
        this.color = color;
        this.isEco = isEco;
    }

    public void setV8(boolean v8) {
        isV8 = v8;
    }

    public void setLongBed(boolean longBed) {
        isLongBed = longBed;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setEco(boolean eco) {
        isEco = eco;
    }
}
