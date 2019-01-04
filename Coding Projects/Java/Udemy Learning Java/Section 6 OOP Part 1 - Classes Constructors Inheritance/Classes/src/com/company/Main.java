package com.company;

public class Main {

    public static void main(String[] args) {
        Car porsche = new Car();
        Car ford = new Car();
        porsche.setModel("FORD");
        System.out.println("Model is " + porsche.getModel());

        String Gavin = "Gavin";
        boolean gav = Gavin.endsWith("n");
        System.out.println(gav);

        double hypotenuse = Math.hypot(10, 10);
        System.out.println(hypotenuse);

        double exponent = Math.pow(5, 3);
        System.out.println(exponent);
    }
}
