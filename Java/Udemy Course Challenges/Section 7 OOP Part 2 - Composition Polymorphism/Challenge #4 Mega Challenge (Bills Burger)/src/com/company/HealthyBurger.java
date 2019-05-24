package com.company;

public class HealthyBurger extends Burger {

    private boolean carrot;
    private boolean spinach;

    public HealthyBurger(String meat, boolean lettuce,
                         boolean pickles, boolean tomato, boolean ketchup, boolean carrot, boolean spinach) {
        super("brown", meat, lettuce, pickles, tomato, ketchup);
        this.carrot = carrot;
        this.spinach = spinach;
    }

    @Override
    public double totalBurgerPrice() {
        double baseBurgerPrice = super.totalBurgerPrice();
        if (carrot) {
            System.out.println("Carrot $.05");
            baseBurgerPrice += .05;
        }
        if (spinach) {
            System.out.println("Spinach $.05");
            baseBurgerPrice += .05;
        }
        System.out.printf("Healthy Burger Grand Total --> $ %.2f %n", baseBurgerPrice);
        return baseBurgerPrice;
    }

}
