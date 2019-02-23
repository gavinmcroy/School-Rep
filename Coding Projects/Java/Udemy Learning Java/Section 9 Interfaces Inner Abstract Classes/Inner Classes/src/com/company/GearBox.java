package com.company;

import java.util.ArrayList;
import java.util.List;

public class GearBox {

    private List<Gear> gearList;
    private int maxGears;
    private int currentGear = 0;
    private boolean clutchIsIn;

    public GearBox(int maxGears) {
        this.maxGears = maxGears;
        this.gearList = new ArrayList<Gear>();
        Gear neutral = new Gear(0, 0.0);
        this.gearList.add(neutral);

        for (int i = 0; i < maxGears; i++) {
            addGear(i, i * 5.3);
        }

    }

    public void operateClutch(boolean in) {
        this.clutchIsIn = in;
    }

    private void addGear(int number, double ratio) {
        if (number > 0 && number <= this.maxGears) {
            this.gearList.add(new Gear(number, ratio));
        }
    }

    public void changeGear(int newGear) {
        if (newGear >= 0 && newGear < this.gearList.size() && this.clutchIsIn) {
            this.currentGear = newGear;
            System.out.println("Gear " + newGear + " has been selected");
        } else {
            System.out.println("Grind!");
            this.currentGear = 0;
        }
    }

    public double wheelSpeed(int rev) {
        if (clutchIsIn) {
            System.out.println("Scream! ");
            return 0.0;
        }
        return rev * gearList.get(currentGear).getRatio();
    }


    private class Gear {

        private int gearNumber;
        private double ratio;

        public Gear(int gearNumber, double ratio) {
            this.gearNumber = gearNumber;
            this.ratio = ratio;
        }

        public double driveSpeed(int rev) {
            return rev * ratio;
        }

        public double getRatio() {
            return ratio;
        }
    }

}
