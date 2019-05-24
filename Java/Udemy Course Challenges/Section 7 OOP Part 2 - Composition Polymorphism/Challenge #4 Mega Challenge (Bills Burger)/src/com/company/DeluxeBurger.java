package com.company;

public class DeluxeBurger extends Burger {

    private boolean chips = true;
    private boolean drink = true;

    public DeluxeBurger(String rollType, String meat) {
        super(rollType, meat, false, false, false, false);
        this.chips = chips;
        this.drink = drink;
    }

    @Override
    public double totalBurgerPrice() {
        double baseBurgerPrice = super.totalBurgerPrice();
        if (chips) {
            System.out.println("Chips $.50");
            baseBurgerPrice += .5;
        }
        if (drink) {
            System.out.println("Drink $.25");
            baseBurgerPrice += .25;
        }
        System.out.printf("Deluxe Burger Grand Total --> $ %.2f %n", baseBurgerPrice);
        return baseBurgerPrice;
    }

}
