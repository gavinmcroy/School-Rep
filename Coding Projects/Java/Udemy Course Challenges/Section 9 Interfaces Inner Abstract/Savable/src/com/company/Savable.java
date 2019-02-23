package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Savable implements ISavable{

    private Scanner scanner = new Scanner(System.in);
    private List<Contact> contactArrayList = new ArrayList<>();

    @Override
    public List<Contact> listContact() {
        return contactArrayList;
    }

    @Override
    public void addObject() {
        System.out.println("Enter the contact name");
        String name = scanner.nextLine();
        System.out.println("Enter the phone number for the contact");
        String number = scanner.nextLine();
        contactArrayList.add(new Contact(name,number));
    }
}
