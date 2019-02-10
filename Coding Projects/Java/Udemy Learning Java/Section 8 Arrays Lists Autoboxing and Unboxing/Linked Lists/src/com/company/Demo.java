package com.company;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Demo {

    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        LinkedList<String> placesToVisit = new LinkedList<>();

        addInOrder("Sydney",placesToVisit);
        addInOrder("Melbourne",placesToVisit);
        addInOrder("Brisbane",placesToVisit);
        addInOrder("Perth",placesToVisit);
        addInOrder("Canberra",placesToVisit);
        addInOrder("Adelaide",placesToVisit);
        addInOrder("Darwin",placesToVisit);
        addInOrder("Alice Springs",placesToVisit);

        printList(placesToVisit);

    }

    private static void printList(LinkedList<String> linkedList) {

        Iterator<String> i = linkedList.iterator();
        while (i.hasNext()) {
            System.out.println("Now Visiting " + i.next());
        }
        System.out.println("===========================");
    }

    private static boolean addInOrder(String newCity, LinkedList<String> linkedList) {
        ListIterator<String> stringListIterator = linkedList.listIterator();
        while (stringListIterator.hasNext()) {
            int comparison = stringListIterator.next().compareTo(newCity);
            if (comparison == 0) {
                System.out.println(newCity + " is already added");
                return false;
            } else if (comparison > 0) {
                stringListIterator.previous();
                stringListIterator.add(newCity);
                return true;
            } else if (comparison < 0) {

            }
        }
        stringListIterator.add(newCity);
        return true;
    }

}
