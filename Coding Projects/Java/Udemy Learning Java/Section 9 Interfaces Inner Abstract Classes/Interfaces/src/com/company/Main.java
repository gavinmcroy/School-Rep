package com.company;

public class Main {

    public static void main(String[] args) {
        ITelephone timPhone;
        timPhone = new DeskPhone(123456);
        timPhone.powerOn();
//        timPhone.answer();
//        timPhone.isRinging();
        timPhone.callPhone(123456);

        timPhone = new MobilePhone(654321);
        timPhone.powerOn();
        timPhone.callPhone(654321);
    }
}
