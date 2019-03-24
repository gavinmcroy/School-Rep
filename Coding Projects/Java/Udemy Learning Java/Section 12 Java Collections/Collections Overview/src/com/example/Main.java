package com.example;

public class Main {

    public static void main(String[] args) {
        Theatre theatre = new Theatre("Skinny G", 8, 12);
        theatre.getSeats();
        if (theatre.reserveSeat("H11")) {
            System.out.println("Pay ! ");
        } else {
            System.out.println(" :( ");
        }
    }
}
