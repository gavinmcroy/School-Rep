package com.company;

public class Main {

    public static void main(String[] args) {
        TV tv =  new TV(new Resolution(1920,1080));
        Dimensions dimensions = new Dimensions(10,10);
        Chair chair = new Chair(new Dimensions(10,10),true);
        Room room = new Room(tv,dimensions,chair);
        System.out.println(chair.isHasCushion());
        room.getTv().turnTVOn();
        room.channelSwitch();
    }
}
