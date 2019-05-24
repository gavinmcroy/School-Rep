package com.company;

public class Room {

    private TV tv;
    private Dimensions dimensions;
    private Chair chair;

    public Room(TV tv, Dimensions dimensions,Chair chair) {
        this.tv = tv;
        this.dimensions = dimensions;
        this.chair=chair;
    }

    public void channelSwitch(){
        tv.turnChannel();
        tv.turnTVOff();
    }

    public TV getTv() {
        return tv;
    }

    public void setTv(TV tv) {
        this.tv = tv;
    }

    public Dimensions getDimensions() {
        return dimensions;
    }

    public void setDimensions(Dimensions dimensions) {
        this.dimensions = dimensions;
    }

    public Chair getChair() {
        return chair;
    }

    public void setChair(Chair chair) {
        this.chair = chair;
    }
}
