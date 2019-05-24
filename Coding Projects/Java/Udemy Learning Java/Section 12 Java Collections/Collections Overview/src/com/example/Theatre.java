package com.example;

import java.util.*;

public class Theatre {

    private final String theatreName;
    public List<Seat> seats = new ArrayList<>();

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
        Seat requestedSeat = new Seat(seatNum);
        int foundSeat = Collections.binarySearch(seats, requestedSeat, null);
        if (foundSeat >= 0) {
            return seats.get(foundSeat).reserve();
        } else {
            System.out.println("There is no seat " + seatNum);
            return false;
        }
    }

    public void getSeats() {
        for (Seat seat : seats) {
            System.out.println(seat.getSeatNumber());
        }
    }

    public String getTheatreName() {
        return theatreName;
    }

    public class Seat implements Comparable<Seat> {
        private final String seatNumber;
        private boolean reserved = false;

        public Seat(String seatNumber) {
            this.seatNumber = seatNumber;
        }

        @Override
        public int compareTo(Seat seat) {
            return this.seatNumber.compareToIgnoreCase(seat.getSeatNumber());
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
