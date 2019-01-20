package com.company;

public class Chair {

    Dimensions dimensions;
    private boolean hasCushion;

    public Chair(Dimensions dimensions, boolean hasCushion) {
        this.dimensions = dimensions;
        this.hasCushion = hasCushion;
    }

    public Dimensions getDimensions() {
        return dimensions;
    }

    public void setDimensions(Dimensions dimensions) {
        this.dimensions = dimensions;
    }

    public boolean isHasCushion() {
        return hasCushion;
    }

    public void setHasCushion(boolean hasCushion) {
        this.hasCushion = hasCushion;
    }
}
