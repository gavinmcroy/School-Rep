package com.company;

public class Main {

    public static void main(String[] args) {
	    printMegaBytesAndKiloBytes(5000);
    }
    public static void printMegaBytesAndKiloBytes(int kiloByte){
        if(kiloByte<0){
            System.out.println("Invalid Value");
        }
        else {
            int megaByte = kiloByte / 1024;
            int kiloByteRemaining = kiloByte %1024;
            System.out.println(kiloByte +" KB = "+megaByte+" MB and "+kiloByteRemaining+" KB");
        }

    }
}
