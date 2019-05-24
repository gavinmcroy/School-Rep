package com.example;

public class SomeClass {

    private static int classCount = 0;
    private String name;
    public final int instanceNumber;

    public SomeClass(String name) {
        this.name = name;
        this.classCount++;
        this.instanceNumber = this.classCount;
        System.out.println(name + "Created instance is" + this.instanceNumber);
    }

    public int getInstanceNumber() {
        return instanceNumber;
    }
}
