package com.company;

public class Printer {

    private int tonerLevel=100;
    private int numberOfPagesPrinted;
    private boolean isDuplexPrinter;

    public Printer(int tonerLevel, boolean isDuplexPrinter) {
        if(tonerLevel>=1&&tonerLevel<=100){
            this.tonerLevel = tonerLevel;
        }
        this.numberOfPagesPrinted = 0;
        this.isDuplexPrinter = isDuplexPrinter;
    }

    public void printPage(int pagesToPrint){
        if(isDuplexPrinter){
            System.out.println("Printing on Duplex Printer");
        }else{
            System.out.println("Printing on Regular Printer");
        }
        tonerLevel-=pagesToPrint;
        numberOfPagesPrinted+=pagesToPrint;
    }

    public int getTonerLevel() {
        return tonerLevel;
    }

    public int getNumberOfPagesPrinted() {
        return numberOfPagesPrinted;
    }

    public boolean isDuplexPrinter() {
        return isDuplexPrinter;
    }
}
