package com.example;


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        Theatre theatre = new Theatre("Skinny G", 8, 12);
        if (theatre.reserveSeat("H11")) {
            System.out.println("Pay ! ");
        } else {
            System.out.println(" :( ");
        }

        if (theatre.reserveSeat("B13")) {
            System.out.println("Pay ! ");
        } else {
            System.out.println(" :( ");
        }

        List<Theatre.Seat> priceSeats = new ArrayList<>(theatre.getSeats());
        priceSeats.add(theatre.new Seat("B00", 13.00));
        priceSeats.add(theatre.new Seat("A00", 13.00));
        Collections.sort(priceSeats, Theatre.PRICE_ORDER);
        printList(priceSeats);
    }

    public static void printList(List<Theatre.Seat> list) {
        for (Theatre.Seat seat : list) {
            System.out.print(" " + seat.getSeatNumber()+" $"+seat.getPrice());
        }
        System.out.println();
        System.out.println("=====================");
    }

}

//        List<Theatre.Seat> seatCopy = new ArrayList<>(theatre.seats);
//        printList(seatCopy);
////        theatre.getSeats();
//        if (theatre.reserveSeat("H11")) {
//            System.out.println("Pay ! ");
//        } else {
//            System.out.println(" :( ");
//        }
//        Theatre.Seat maxSeat = Collections.max(seatCopy);
//        Theatre.Seat minSeat = Collections.min(seatCopy);
//        System.out.println("MIN --> " + minSeat.getSeatNumber() + " MAX --> " + maxSeat.getSeatNumber());
//
//        sortList(seatCopy);
//        System.out.println("-");
//        printList(seatCopy);
//    }
//
//    public static void printList(List<Theatre.Seat> list) {
//        for (Theatre.Seat seat : list) {
//            System.out.print(" " + seat.getSeatNumber());
//        }
//        System.out.println();
//        System.out.println("=====================");
//    }
//
//    public static void sortList(List<? extends Theatre.Seat> list) {
//        for (int i = 0; i < list.size(); i++) {
//            for (int j = i + 1; j < list.size(); j++) {
//                if (list.get(i).compareTo(list.get(j)) > 0) {
//                    Collections.swap(list, i, j);
//                }
//            }
//        }
//    }
