package com.company;

public class Main {

    public static void main(String[] args) {
        VipCustomer gavinM = new VipCustomer();
        System.out.println(gavinM.getCreditLimit());
        System.out.println(gavinM.getEmailAddress());
        System.out.println(gavinM.getName());

        VipCustomer kai = new VipCustomer("Kai", "garbo34@gmail.com");
        System.out.println(kai.getCreditLimit());
        System.out.println(kai.getEmailAddress());
        System.out.println(kai.getName());

        VipCustomer jack = new VipCustomer("Jack", "JackG@gmail.com", 6700);
        System.out.println(jack.getCreditLimit());
        System.out.println(jack.getEmailAddress());
        System.out.println(jack.getName());
    }
}
