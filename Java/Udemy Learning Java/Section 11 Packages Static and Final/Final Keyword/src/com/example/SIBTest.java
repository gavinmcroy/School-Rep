package com.example;

public class SIBTest {

    public static final String owner;

    static {
        owner = "tim";
        System.out.println("SIB Test block #1 called");
    }

    public SIBTest() {
        System.out.println("SIB Constructor call");
    }

    static {
        System.out.println("Second block called");
    }

    public void someMethod() {
        System.out.println("Some method call ");
    }

}
