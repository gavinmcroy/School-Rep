package com.company;

import java.util.ArrayList;

public class Customers {

    private String name;
    private ArrayList<Double> transactions;

    public Customers(String name, double initialAmount) {
        this.name = name;
        this.transactions = new ArrayList<>();
        transactions.add(initialAmount);
    }

    public String getName() {
        return name;
    }

    public ArrayList<Double> getTransactions() {
        return transactions;
    }
}
