package com.company;

public class Main {

    public static void main(String[] args) {
	    Animal animal = new Animal(1,1,1,50,"Animal");
	    Dog dog = new Dog(1,3,"Yorkshire",1,1,1,40,"Long");
	    dog.eat();
	    dog.walk();
	    dog.run();
    }
}
