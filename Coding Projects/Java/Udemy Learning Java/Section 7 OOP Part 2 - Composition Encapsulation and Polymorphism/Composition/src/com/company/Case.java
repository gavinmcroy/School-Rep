package com.company;


public class Case {

    private String model;
    private String manufacturer;
    private String powerSupply;
    private Dimensions caseDimensions;

    public Case(String model, String manufacturer, String powerSupply, Dimensions caseDimensions) {
        this.model = model;
        this.manufacturer = manufacturer;
        this.powerSupply = powerSupply;
        this.caseDimensions = caseDimensions;
    }

    public void pressPowerButton(){
        System.out.println("Power button Pressed");
    }

    public String getModel() {
        return model;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    public String getPowerSupply() {
        return powerSupply;
    }

    public Dimensions getCaseDimensions() {
        return caseDimensions;
    }
}
