package com.company;

public class DeskPhone implements ITelephone {

    private int myPhoneNumber;
    private boolean isRinging;

    public DeskPhone(int myPhoneNumber) {
        this.myPhoneNumber = myPhoneNumber;
    }

    @Override
    public void powerOn() {
        System.out.println("No action taken , no power button");
    }

    @Override
    public void dial(int phoneNumber) {
        System.out.println("Now ringing " + phoneNumber + " on desk phone");
    }

    @Override
    public void answer() {
        if (isRinging) {
            System.out.println("Answering desk phone");
            this.isRinging = false;
        }
    }

    @Override
    public boolean callPhone(int phoneNumber) {
        if (phoneNumber == myPhoneNumber) {
            isRinging = true;
            System.out.println("Is ringing my phone");
        } else {
            isRinging = false;
        }
        return isRinging;
    }

    @Override
    public boolean isRinging() {
        return isRinging;
    }
}
