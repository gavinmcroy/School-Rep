package com.example;

import java.util.Scanner;

public class X {

//    private Scanner x = new Scanner(System.in);
    private int x;

    public X() {
        Scanner x  = new Scanner(System.in);
        this.x = x(x);
        x();
    }

    public void x() {
        for(int x = 1; x<=12;x++){
            System.out.println(this.x*x);
        }
    }
    public int x(Scanner x){
        x = new Scanner(System.in);
        return x.nextInt();
    }

}
