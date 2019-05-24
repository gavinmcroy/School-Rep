package com.company;

public class Main {

    public static void main(String[] args) {
        Burger burger = new Burger("white", "meat", true, true, true, true);
//        burger.totalBurgerPrice();
        HealthyBurger healthyBurger = new HealthyBurger("meat",true,true,true,
                true,true,true);
//        healthyBurger.totalBurgerPrice();
        DeluxeBurger deluxeBurger = new DeluxeBurger("white","meat");
        deluxeBurger.totalBurgerPrice();
    }
}
