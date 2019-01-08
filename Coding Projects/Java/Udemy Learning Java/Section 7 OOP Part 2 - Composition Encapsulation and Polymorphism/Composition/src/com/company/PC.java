package com.company;

public class PC {

    private Case theCase;
    private Monitor monitors;
    private MotherBoard motherBoards;

    public PC(Case theCase, Monitor monitors, MotherBoard motherBoards) {
        this.theCase = theCase;
        this.monitors = monitors;
        this.motherBoards = motherBoards;
    }

    public void powerUp(){
        theCase.pressPowerButton();
        drawLogo();
    }

    private void drawLogo(){
        monitors.drawPixelAt(1,1,"Blue");
    }

//    private Case getTheCase() {
//        return theCase;
//    }
//
//    private Monitor getMonitors() {
//        return monitors;
//    }
//
//    private MotherBoard getMotherBoards() {
//        return motherBoards;
//    }
}
