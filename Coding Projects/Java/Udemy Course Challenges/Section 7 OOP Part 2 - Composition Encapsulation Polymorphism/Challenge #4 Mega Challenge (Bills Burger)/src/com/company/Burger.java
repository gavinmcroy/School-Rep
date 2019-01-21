package com.company;

public class Burger {

    private String rollType;
    private String meat;
    private boolean lettuce;
    private boolean pickles;
    private boolean tomato;
    private boolean ketchup;

    public Burger(String rollType, String meat, boolean lettuce, boolean pickles, boolean tomato, boolean ketchup) {
        this.rollType = rollType;
        this.meat = meat;
        this.lettuce = lettuce;
        this.pickles = pickles;
        this.tomato = tomato;
        this.ketchup = ketchup;
    }

    public double totalBurgerPrice() {
        double burgerPrice = 0d;
        this.rollType = rollType.toLowerCase();
        this.meat = meat.toLowerCase();
        if (rollType.equals("white") || rollType.equals("brown")) {
            System.out.println("Roll $1.00 ");
            burgerPrice += 1.00;
        }
        if (meat.equals("meat")) {
            System.out.println("Meat Paddie $.50");
            burgerPrice += .50;
        } else {
            System.out.println("Invalid Option");
        }
        if (lettuce) {
            System.out.println("Lettuce .$25");
            burgerPrice += .25;
        }
        if (pickles) {
            System.out.println("Pickles $.05");
            burgerPrice += .05;
        }
        if (tomato) {
            System.out.println("Tomato $.25");
            burgerPrice += .25;
        }
        if (ketchup) {
            System.out.println("Ketchup $.05");
            burgerPrice += .05;
        }
        System.out.printf("Base Total --> $ %.2f %n", burgerPrice);
        return burgerPrice;
    }


}
