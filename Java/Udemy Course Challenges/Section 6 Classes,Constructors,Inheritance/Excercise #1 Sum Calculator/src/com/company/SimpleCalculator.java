package com.company;

public class SimpleCalculator {

    private double firstNumber;
    private double secondNumber;

    // public SimpleCalculator(double firstNumber,double secondNumber){
    //     this.firstNumber=firstNumber;
    //     this.secondNumber=secondNumber;
    // }

    public double getFirstNumber() {
        return firstNumber;
    }

    public double getSecondNumber() {
        return secondNumber;
    }

    public void setFirstNumber(double setVal) {
        this.firstNumber = setVal;
    }

    public void setSecondNumber(double setVal) {
        this.secondNumber = setVal;
    }

    public double getAdditionResult() {
        return firstNumber + secondNumber;
    }

    public double getSubtractionResult() {
        return firstNumber - secondNumber;
    }

    public double getMultiplicationResult() {
        return firstNumber * secondNumber;
    }

    public double getDivisionResult() {
        if (secondNumber == 0) {
            return 0;
        }
        return firstNumber / secondNumber;
    }
}
