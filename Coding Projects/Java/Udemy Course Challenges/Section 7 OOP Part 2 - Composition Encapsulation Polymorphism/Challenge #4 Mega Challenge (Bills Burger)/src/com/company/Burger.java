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

    //---Takes  price from burger main and checks for accessories
    public double burgerAccesories(double currentBurgerPrice) {
        if (lettuce) {
            currentBurgerPrice += .25;
        }
        if (pickles) {
            currentBurgerPrice += .05;
        }
        if (tomato) {
            currentBurgerPrice += .25;
        }
        if (ketchup) {
            currentBurgerPrice += .05;
        }
        return currentBurgerPrice;
    }

    public double burgerMain() {
        double burgerPrice = 0;
        this.rollType=rollType.toLowerCase();
        this.meat = meat.toLowerCase();
        if (rollType.equals("white")) {
            burgerPrice += 1.00;
        }
        if (meat.equals("meat")) {
            burgerPrice += .50;
        } else {
            return -1;
        }
        return burgerPrice;
    }
}
