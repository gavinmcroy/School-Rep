package com.company;

public class Car {

    private int doors;
    private int numberOfDoors;
    private String model;
    private String engine;
    private String color;

    public void setModel(String model){
        String validModel = model.toLowerCase();
        if(validModel.equals("porsche")||(validModel.equals("ford"))){
            this.model = model;
        }else{
            this.model = "Unknown";
        }
    }

    public String getModel(){
        return this.model;
    }
}
