package com.company;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    private static GroceryList groceryList = new GroceryList();

    public static void main(String[] args) {
        boolean quit = false;
        int choice = 0;
        printInstructions();
        while (!quit) {
            System.out.println("Enter your choice: (Number) ");
            choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 0:
                    printInstructions();
                    break;
                case 1:
                    groceryList.printGroceryList();
                    break;
                case 2:
                    addItem();
                    break;
                case 3:
                    modifyItem();
                    break;
                case 4:
                    removeItem();
                    break;
                case 5:
                    searchForItem();
                    break;
                case 6:
                    processArrayList();
                case 7:
                    quit = true;
                    break;
            }
        }
    }

    private static void printInstructions() {
        System.out.println("0. Print choice Options");
        System.out.println("1. Print grocery list");
        System.out.println("2. Add item to grocery list");
        System.out.println("3. Modify item on grocery list");
        System.out.println("4. Remove item from grocery list");
        System.out.println("5. Search for item from grocery list ");
        System.out.println("6. Quit application");
    }

    private static void addItem() {
        System.out.println("Please enter the grocery item");
        groceryList.addGroceryItem(scanner.nextLine());
    }

    private static void modifyItem() {
        System.out.println("Enter item name");
        String item = scanner.nextLine();
        System.out.println("Enter replacement item ");
        String newItem = scanner.nextLine();
        groceryList.modifyGroceryElement(item, newItem);
    }

    private static void removeItem() {
        System.out.println("Enter the item name");
        String item = scanner.nextLine();
        groceryList.removeGroceryItem(item);
    }

    private static void searchForItem() {
        System.out.println("Enter a item to search for: ");
        String searchItem = scanner.nextLine();
        if (groceryList.onFile(searchItem)) {
            System.out.println("Found " + searchItem + " in grocery list");
        } else {
            System.out.println("Did not find item in grocery list");
        }
    }
    private static void processArrayList(){
        ArrayList<String> newArray = new ArrayList<>();
        newArray.addAll(groceryList.getGroceryList());

        ArrayList<String> anotherWay = new ArrayList<>(groceryList.getGroceryList());

        String[] myArray = new String[groceryList.getGroceryList().size()];
        myArray = groceryList.getGroceryList().toArray(myArray);
    }
}
