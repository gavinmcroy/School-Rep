package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class MobilePhone {

    private Scanner scanner = new Scanner(System.in);
    private ArrayList<Contacts> contacts = new ArrayList<>();

    public void addContact() {
        System.out.println("Enter the contact name");
        String name = scanner.nextLine();
        boolean createContact = true;
        System.out.println("Enter the Phone Number ");
        String phoneNumber = scanner.nextLine();
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getName().equals(name)) {
                System.out.println("Contact name already exists");
                createContact = false;
                break;
            } else if (contacts.get(i).getPhoneNumber().equals(phoneNumber)) {
                System.out.println("Phone number already exists");
                createContact = false;
                break;
            }
        }
        if (createContact) {
            System.out.println("Successfully created new contact! ");
            contacts.add(new Contacts(name, phoneNumber));
        }
    }

    public void printContact() {
        System.out.println("Current Contacts");
        for (int i = 0; i < contacts.size(); i++) {
            System.out.println("Contact #" + (i + 1));
            System.out.println(contacts.get(i).getName());
            System.out.println(contacts.get(i).getPhoneNumber());
        }
    }

    public void updateCurrentContact() {
        boolean successfulUpdate = false;
        System.out.println("Enter the name of the contact you wish to update");
        String oldName = scanner.nextLine();
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getName().equals(oldName)) {
                System.out.println("Enter the new name of the contact");
                String name = scanner.nextLine();
                System.out.println("Enter the new phone number of the contact");
                String phoneNumber = scanner.nextLine();
                contacts.set(i, new Contacts(name, phoneNumber));
                successfulUpdate = true;
                break;
            }
        }
        if (successfulUpdate) {
            System.out.println("Successfully updated contact! ");
        } else {
            System.out.println("Couldn't find the contact you requested to update");
        }
    }

    public void removeContact() {
        System.out.println("Enter the name of the contact you wish to remove");
        boolean successfullyRemoved = false;
        String oldName = scanner.nextLine();
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getName().equals(oldName)) {
                contacts.remove(i);
                System.out.println("Contact " + oldName + " Removed");
                successfullyRemoved = true;
                break;
            }
        }
        if (!successfullyRemoved) {
            System.out.println("Couldn't find the contact you requested to remove");
        }
    }

    public void searchContact() {
        System.out.println("Enter the name of the contact you wish to search");
        boolean contactFound = false;
        String name = scanner.nextLine();
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts.get(i).getName().equals(name)) {
                System.out.println("Contact name: " + name + " has been found! ");
                contactFound = true;
                break;
            }
        }
        if (!contactFound) {
            System.out.println("Couldn't find the contact you requested to search");
        }
    }
}
