package com.company;

public class Main {

    public static void main(String[] args) {
        DOg dog = new DOg("Yorkie");
        dog.breathe();
        dog.eat();
        Parrot parrot = new Parrot("Parrot");
        parrot.breathe();
        parrot.fly();
        parrot.eat();
        Penguin penguin = new Penguin("Penguin");
        penguin.fly();
        penguin.eat();
    }
}
