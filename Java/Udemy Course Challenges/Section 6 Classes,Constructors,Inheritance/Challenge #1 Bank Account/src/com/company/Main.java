package com.company;

public class Main {

    public static void main(String[] args) {

        //---No parameters called first constructor called then calls overloaded constructor
        //Account dave = new Account();
        Account dave = new Account(10,0,"Dave",
                "Dave.gg@gmail.com","843-300-5147");
//        dave.setAccountNumber(10);
//        dave.setBalance(0);
//        dave.setName("Dave");
//        dave.setEmail("Dave.gg@gmail.com");
//        dave.setPhoneNumber("843-300-5147");
        System.out.println(dave.getName());
        System.out.println(dave.getEmail());

        dave.depositFunds(50);
        dave.withDrawFunds(150);

        Account gavinsAccount = new Account("Gavin","Gg","32");
        System.out.println(gavinsAccount.getEmail());
    }
}
