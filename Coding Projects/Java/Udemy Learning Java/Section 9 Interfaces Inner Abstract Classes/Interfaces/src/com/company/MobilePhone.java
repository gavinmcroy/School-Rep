package com.company;

public class MobilePhone implements ITelephone {

    private int myPhoneNumber;
    private boolean isRinging;
    private boolean isOn = true;

    public MobilePhone(int myPhoneNumber) {
        this.myPhoneNumber = myPhoneNumber;
    }

    @Override
    public void powerOn() {
        this.isOn = true;
        System.out.println("Mobile phone powered up ");
    }

    @Override
    public void dial(int phoneNumber) {
        if (isOn) {
            System.out.println("Now ringing " + phoneNumber + " on desk phone");
        } else {
            System.out.println("Phone is switched off ");
        }
    }

    @Override
    public void answer() {
        if (isRinging) {
            System.out.println("Answering mobile phone");
            this.isRinging = false;
        }
    }

    @Override
    public boolean callPhone(int phoneNumber) {
        if (phoneNumber == myPhoneNumber && isOn) {
            isRinging = true;
            System.out.println("Is ringing my mobile phone");
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
