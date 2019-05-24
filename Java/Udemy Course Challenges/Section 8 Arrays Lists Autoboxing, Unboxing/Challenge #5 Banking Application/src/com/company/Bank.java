package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Bank {

    private Scanner scanner = new Scanner(System.in);
    private ArrayList<Branches> branches = new ArrayList<>();

    public void addBranch() {
        System.out.println("Enter a name for the new branch");
        String branchName = scanner.nextLine();
        branches.add(new Branches(branchName));
        System.out.println("Successfully Added new Branch! ");
    }

    public void addCustomerToBranch() {
        System.out.println("Enter the branch for the customer");
        String branch = scanner.nextLine();
        int branchLocation = 0;
        boolean foundBranch = false;
        for (int i = 0; i < branches.size(); i++) {
            if (branches.get(i).getBranchName().equals(branch)) {
                foundBranch = true;
                branchLocation = i;
            }
        }
        if (foundBranch) {
            //---Adds customer to customer Array List
            branches.get(branchLocation).addCustomer();
        } else {
            System.out.println("Enter a valid branch name");
        }
    }

    public void addTransaction() {
        if (findBranch() != -1) {
            System.out.println("Enter the name of the customer ");
            String customerName = scanner.nextLine();
            int customerLocation = 0;
            boolean foundCustomer = false;
            for (int i = 0; i < branches.size(); i++) {
                if (branches.get(i).getCustomers().get(i).getName().equals(customerName)) {
                    foundCustomer = true;
                    customerLocation = i;
                }
            }
            if (foundCustomer) {
                System.out.println("Enter the transaction you wish to add to " + branches.get
                        (customerLocation).getCustomers().get(customerLocation).getName());
                boolean hasNextDouble = scanner.hasNextDouble();
                if (hasNextDouble) {
                    double transactionAmount = scanner.nextDouble();
                    scanner.nextLine();
                    branches.get(customerLocation).getCustomers().get(customerLocation).getTransactions().add(transactionAmount);
                    System.out.println("Successfully added " + transactionAmount);
                }
            } else {
                System.out.println("Enter a valid customer name");
            }
        } else {
            System.out.println("Enter a valid branch name");
        }
    }

    public void showCustomersInBranch() {
        int branchLocation = findBranch();
        if (branchLocation != -1) {
            for (int i = 0; i < branches.get(branchLocation).getCustomers().size(); i++) {
                System.out.println("Customer #" + (i + 1) + " " + branches.get(branchLocation).getCustomers().get(i).getName());
            }
        } else {
            System.out.println("Enter valid branch name");
        }
    }

    public int showTransactionsForCustomer() {
        int x = findBranch();
        if (x == -1) {
            return -1;
        }
        for (int i = 0; i < branches.get(x).getCustomers().size(); i++) {
            System.out.println("Customer name: " + branches.get(x).getCustomers().get(i).getName());
            System.out.println("Transactions: " + branches.get(x).getCustomers().get(i).getTransactions());
        }
        return 1;
    }

    private int findBranch() {
        System.out.println("Enter the branch name");
        String branch = scanner.nextLine();
        int branchLocation = -1;
        for (int i = 0; i < branches.size(); i++) {
            if (branches.get(i).getBranchName().equals(branch)) {
                branchLocation = i;
            }
        }
        return branchLocation;
    }

    public ArrayList<Branches> getBranches() {
        return branches;
    }

}
