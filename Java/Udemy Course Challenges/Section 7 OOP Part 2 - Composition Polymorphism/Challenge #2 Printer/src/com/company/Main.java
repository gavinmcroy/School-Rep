package com.company;

public class Main {

    public static void main(String[] args) {
	    Printer printer = new Printer(2000,1,true);
	    printer.printPage(20);
        System.out.println(printer.getTonerLevel());
        System.out.println(printer.getNumberOfPagesPrinted());
        System.out.println(printer.isDuplexPrinter());
    }
}
