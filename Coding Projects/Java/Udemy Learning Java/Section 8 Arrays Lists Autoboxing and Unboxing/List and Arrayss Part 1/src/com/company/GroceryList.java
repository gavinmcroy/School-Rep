package com.company;

import java.util.ArrayList;

public class GroceryList {

    private ArrayList<String> groceryList = new ArrayList<>();

    public void addGroceryItem(String item) {
        groceryList.add(item);
    }

    public ArrayList<String> getGroceryList() {
        return groceryList;
    }

    public void printGroceryList() {
        System.out.println("You have " + groceryList.size() + " items in your list");
        for (int i = 0; i < groceryList.size(); i++) {
            System.out.println((i + 1) + "." + groceryList.get(i));
        }
    }

    public void modifyGroceryElement(String currentItem,String newItem) {
        int position = findItem(currentItem);
        if(position>=0){
            modifyGroceryElement(position,newItem);
        }
    }

    private void modifyGroceryElement(int position, String newItem) {
        groceryList.set(position, newItem);
        System.out.println("Grocery item " + groceryList.get(position) + " was replaced");
    }

    public void removeGroceryItem(String item){
        int position = findItem(item);
        if(position>=0){
            removeGroceryItem(position);
        }
    }

    private void removeGroceryItem(int position) {
        groceryList.remove(position);
    }

    private int findItem(String searchItem) {
        return groceryList.indexOf(searchItem);
    }

    public boolean onFile(String searchItem){
        int position = findItem(searchItem);
        if(position>=0){
            return true;
        }else{
            return false;
        }
    }
}