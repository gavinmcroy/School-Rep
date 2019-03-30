package com.example;

public class Room {

    private int width;
    private int height;
    private int roomArea = width * height;

    public Room(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public int getRoomArea() {
        return roomArea;
    }
}
