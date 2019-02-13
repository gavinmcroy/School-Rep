package com.company;

public class ComplexNumber {

    private double real;
    private double imaginary;

    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getReal() {
        return this.real;
    }

    public double getImaginary() {
        return this.imaginary;
    }

    public String add(double real, double imaginary) {
        if (this.imaginary + imaginary == 1) {
            return (this.real + real) + " + i";
        } else {
            return (this.real + real) + " + " + (this.imaginary + imaginary) + "i";
        }
    }

    public String add(ComplexNumber complexNumber) {
        return add(complexNumber.getReal(), complexNumber.getImaginary());
    }

    public String subtract(double real, double imaginary) {
        if (this.imaginary - imaginary == 1) {
            return (this.real - real) + " + i";
        } else {
            return (this.real - real) + " - " + (this.imaginary - imaginary) + "i";
        }
    }

    public String subtract(ComplexNumber complexNumber) {
        return subtract(complexNumber.getReal(), complexNumber.getImaginary());

    }

}
