package com.company;

public class VipCustomer {

    private String name;
    private String emailAddress;
    private int creditLimit;

    public VipCustomer(String name, String emailAddress, int creditLimit) {
        this.name = name;
        this.emailAddress = emailAddress;
        this.creditLimit = creditLimit;
    }

    public VipCustomer(String name, String emailAddress) {
        this(name,emailAddress,250);
    }

    public VipCustomer() {
        this("Unknown", "Unknown@bigbank.com", 250);
        System.out.println("Default Constructor!");
    }

    public String getName() {
        return name;
    }

    public String getEmailAddress() {
        return emailAddress;
    }

    public int getCreditLimit() {
        return creditLimit;
    }

}
