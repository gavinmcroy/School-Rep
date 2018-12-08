package com.company;

public class Main {

    public static final String ERROR_MESSAGE = "Invalid Value";

    public static void main(String[] args) {
        String timeCalc = getDurationString(61, 0);
        System.out.println(timeCalc);
        String timeCalc1 = getDurationString(519);
        System.out.println(timeCalc1);
    }

    public static String getDurationString(double minutes, double seconds) {
        if (minutes >= 0 && (seconds >= 0 && seconds <= 59)) {
            double second = seconds + (minutes * 60);
            double minute = seconds / 60 + minutes;
            double hour = seconds / 3200 + minutes / 60;
            return "Hour: " + hour + " Minute: " + minute + " Second: " + second;
        } else {
            return ERROR_MESSAGE;
        }
    }

    public static String getDurationString(double seconds) {
        if (seconds >= 0) {
            double minute = seconds / 60;
            seconds = 0;
            return getDurationString(minute, seconds);
        } else {
            return ERROR_MESSAGE;
        }
    }
}
