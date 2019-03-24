package com.example;

public class Main {

    public static void main(String[] args) {
        Account account = new Account("Gav");
        account.deposit(20);
        account.withdraw(500);
        account.withdraw(-10);
        account.deposit(-1);
        account.calculateBalance();
        account.calculateBalance();
    }
}
