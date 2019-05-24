package com.company;

public class Main {

    public static void main(String[] args) {
        Dimensions dimensions = new Dimensions(20,20,5);
	    Case theCase = new Case("22B","Dell","240",dimensions);
	    Monitor monitor = new Monitor("27 Boy","Dell",27,new Resolution(1920,1080));
	    MotherBoard motherBoard = new MotherBoard("200","MSI",4,4,"221");
	    PC thePC = new PC(theCase,monitor,motherBoard);
//	    thePC.getMonitors().drawPixelAt(1,1,"Red");
//	    thePC.getMotherBoards().programLoader("Windows32.exe");
//	    thePC.getTheCase().pressPowerButton();
        thePC.powerUp();


    }
}
