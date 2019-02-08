package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Branches {

    private Scanner scanner = new Scanner(System.in);
    private ArrayList<Customers> customers = new ArrayList<>();
    private String branchName;

    public Branches(String branchName) {
        this.branchName = branchName;
    }

    public void addCustomer() {
        System.out.println("Enter the name of the new user");
        String name = scanner.nextLine();
        System.out.println("Enter the transaction amount");
        boolean isDouble = scanner.hasNextDouble();
        if (isDouble) {
            double amount = scanner.nextDouble();
            scanner.nextLine();
            customers.add(new Customers(name, amount));
            System.out.println("New Customer Successfully Added! ");
        } else {
            System.out.println("Invalid Input Please Try Again");
        }
    }

    public ArrayList<Customers> getCustomers() {
        return customers;
    }

    public String getBranchName() {
        return branchName;
    }
}
