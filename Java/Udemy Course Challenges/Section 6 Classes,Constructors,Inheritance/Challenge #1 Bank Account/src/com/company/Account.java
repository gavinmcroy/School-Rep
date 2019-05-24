package com.company;

import java.util.Scanner;

public class Account {
    private int accountNumber;
    private int balance;
    private String name;
    private String email;
    private String phoneNumber;

    //---Constructor
    public Account() {
        //---Default parameters
        this(1,2,"3","4","5");
        System.out.println("Empty Constructor");
    }
    //---Overloaded Constructor
    public Account(int accountNumber,int balance,String name,String email,String phoneNumber){
        System.out.println("Constructor with Parameters Called");
        this.accountNumber=accountNumber;
        this.balance=balance;
        this.name=name;
        this.email=email;
        this.phoneNumber=phoneNumber;
    }
    //---Constructor
    public Account(String name, String email, String phoneNumber) {
        this(4545,10,"Gavin","gavinT@gmail.com","843-300-5147");
    }

    public void depositFunds(int depositAmount) {
        if (depositAmount > 0) {
            balance += depositAmount;
            System.out.println("Added $"+balance);
            System.out.println("New balance of " + balance);
        } else {
            System.out.println("Enter valid Input");
        }
    }

    public void withDrawFunds(int withDrawAmount) {
        if (withDrawAmount > 0) {
            if(balance-withDrawAmount>0){
                balance -= withDrawAmount;
                System.out.println("New balance of " + balance);
            }else{
                System.out.println("Invalid Balance for Withdraw. Balance of "+balance);
            }
        } else {
            System.out.println("Enter valid Input");
        }
    }


    public void setAccountNumber(int accountNumber) {
        this.accountNumber = accountNumber;
    }

    public int getAccountNumber() {
        return this.accountNumber;
    }

    public void setBalance(int balance) {
        this.balance = balance;
    }

    public int getBalance() {
        return this.balance;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getEmail() {
        return this.email;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getPhoneNumber() {
        return this.phoneNumber;
    }
}
