package com.example;

import java.util.ArrayList;
import java.util.List;

public class Theatre {

    private final String theatreName;
    private List<Seat> seats = new ArrayList<>();

    public Theatre(String theatreName, int numRows, int seatsPerRow) {
        this.theatreName = theatreName;

        int lastRow = 'A' + (numRows - 1);
        for (char row = 'A'; row <= lastRow; row++) {
            for (int seatNum = 1; seatNum <= seatsPerRow; seatNum++) {
                Seat seat = new Seat(row + String.format("%02d", seatNum));
                seats.add(seat);
            }
        }
    }

    public boolean reserveSeat(String seatNum) {
        Seat requestedSeat = null;
        for (Seat seat : seats) {
            if (seat.getSeatNumber().equals(seatNum)) {
                requestedSeat = seat;
                break;
            }
        }
        if (requestedSeat == null) {
            System.out.println("No seat available");
            return false;
        }
        return requestedSeat.reserve();
    }

    public void getSeats() {
        for (Seat seat : seats) {
            System.out.println(seat.getSeatNumber());
        }
    }

    public String getTheatreName() {
        return theatreName;
    }

    private class Seat {
        private final String seatNumber;
        private boolean reserved = false;

        public Seat(String seatNumber) {
            this.seatNumber = seatNumber;
        }

        public boolean reserve() {
            if (!this.reserved) {
                this.reserved = true;
                System.out.println("Seat " + seatNumber + " Reserved");
                return true;
            } else {
                return false;
            }
        }

        public boolean cancelled() {
            if (this.reserved) {
                this.reserved = false;
                System.out.println("Reservation of seat " + seatNumber + " cancelled");
                return true;
            } else {
                System.out.println("Unable to cancel seat was not reserved");
                return false;
            }
        }

        public String getSeatNumber() {
            return seatNumber;
        }
    }

}
