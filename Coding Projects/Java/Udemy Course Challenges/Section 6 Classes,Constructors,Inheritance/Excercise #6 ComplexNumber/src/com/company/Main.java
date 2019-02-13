package com.company;

public class Main {

    public static void main(String[] args) {
        ComplexNumber complexNumber = new ComplexNumber(1, 2);
        ComplexNumber betterComplex  = new ComplexNumber(1,1);
        System.out.println(complexNumber.add(1, -1));
        System.out.println(complexNumber.add(betterComplex));
        System.out.println(complexNumber.subtract(1,1));
        System.out.println(complexNumber.subtract(betterComplex));
    }
}
