package com.company;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
	    for(int i = 0; i<=11;i++){
	        Car car = polymorphism();
            System.out.println("Car #"+i+":");
            car.startEngine();
            car.accelerate();
        }
    }
    public static Car polymorphism(){
        int randomNum = (int) (Math.random()*3)+1;
        System.out.println("Random num Gen: "+randomNum);
        switch(randomNum){
            case 1:
                return new Ferrari(1,1,1);
            case 2:
                return new Mclaren(1,1,1);
            case 3:
                return new Junk(1,1,1,1);
            default:
                return null;
        }
    }
}
