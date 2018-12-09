package com.company;

public class Main {

    public static void main(String[] args) {
//        for (int i = 8; i >= 2; i--) {
//            System.out.println(calcInterest(10_000, i));
//        }
        int count = 0;
        for(int i = 2; i<=50; i++){
            boolean prime = isPrime(i);
            if(prime){
                System.out.println(i);
                count++;
            }
            if(count==3)
                break;
        }
    }

    public static double calcInterest(double amount, double interestRate) {
        return (amount * interestRate) / 100;
    }

    private static boolean isPrime(int n) {

        if (n == 1) {
            return false;
        }
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
