package com.company;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        Customer customer = new Customer("Gavin", 15.50);
        Customer anotherCustomer;
        anotherCustomer = customer;
        anotherCustomer.setBalance(12.18);
        System.out.println("Balance for customer " + customer.getName() + " is " + customer.getBalance());

        ArrayList<Integer> myInt = new ArrayList<>();
        myInt.add(12);
        myInt.add(32);
        myInt.add(4);
        for (int i = 0; i < myInt.size(); i++) {
            System.out.println("Position " + i + ": " + myInt.get(i));
        }

        myInt.add(2, 250);

        for (int i = 0; i < myInt.size(); i++) {
            System.out.println("Second ArrayList Position " + i + ": " + myInt.get(i));
        }
    }
}
