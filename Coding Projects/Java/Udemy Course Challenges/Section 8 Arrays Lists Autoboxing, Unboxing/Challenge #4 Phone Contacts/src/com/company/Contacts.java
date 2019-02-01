package com.company;

public class Contacts {

    private String name;
    private String phoneNumber;

    public Contacts(String name, String phoneNumber) {
        this.name = name;
        this.phoneNumber = phoneNumber;
    }

    public Contacts() {
        this("Unknown", "Unknown");
    }

    public String getName() {
        return name;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }
}
