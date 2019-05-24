package com.example;

public class Main {

    public static void main(String[] args) {
//        SomeClass someClass1 = new SomeClass("SomeClass1");
////        SomeClass someClass2 = new SomeClass("SomeClass2");
////        SomeClass someClass3 = new SomeClass("SomeClass3");
////
////        System.out.println(someClass1.getInstanceNumber());
////        System.out.println(someClass2.getInstanceNumber());
////        System.out.println(someClass3.getInstanceNumber());
////
////        Test test = Test.instanceGeneration();
////
////        int pass = 7485;
////        ExtendedPass password = new ExtendedPass(pass);
////        password.storePass();
////        password.letMeIn(pass);
        System.out.println("Main method");
        SIBTest sibTest = new SIBTest();
        sibTest.someMethod();
        System.out.println("Owner is " + SIBTest.owner);
    }
}
