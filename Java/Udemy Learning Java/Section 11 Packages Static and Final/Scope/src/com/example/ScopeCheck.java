package com.example;

public class ScopeCheck {

    public int publicVar = 0;
    private int privateVar = 1;
    protected int protectedInt = 2;

    public ScopeCheck() {
        System.out.println("Private var "+privateVar+": public Var "+ publicVar);
    }

    public int getPrivateVar() {
        return privateVar;
    }

    public void timesTwo(){
        int privateVar = 2;
        for(int i =0; i<10;i++){
            System.out.println(i*privateVar);
        }
    }

}
