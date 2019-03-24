package com.company;

public class Penguin extends Bird {

    public Penguin(String name) {
        super(name);
    }

    @Override
    public void fly() {
        System.out.println(getName() + " cannot fly! ");
    }

    @Override
    public void eat() {
        System.out.println(getName() + " is doing things");
    }
}
