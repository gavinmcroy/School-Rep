package com.example.mypackage;

public class Series {

    private final double PHI_NUMBER = 1.618033989d;

    public Series() {

    }

    public int nSum(int n) {
        int startVal = 0;
        for (int i = 0; i < n; i++) {
            startVal += i;
        }
        return startVal;
    }

    public int factorial(int n) {
        int startVal = 1;
        for (int i = 1; i <= n; i++) {
            startVal *= i;
        }
        return startVal;
    }

    public int fibonacci(int nthNum) {
        double fibonacciNumber = Math.round(Math.pow(PHI_NUMBER, nthNum) / Math.sqrt(5));
        return (int) fibonacciNumber;
    }

}
