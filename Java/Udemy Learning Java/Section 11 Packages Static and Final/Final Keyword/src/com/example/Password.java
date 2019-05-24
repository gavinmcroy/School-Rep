package com.example;

public class Password {

    private static final int key = 7485;
    private final int encryptedPass;

    public Password(int encryptedPass) {
        this.encryptedPass = encryptDecrypt(encryptedPass);
    }

    public boolean letMeIn(int password) {
        if (encryptDecrypt(password) == this.encryptedPass) {
            System.out.println("WOW !");
            return true;
        } else {
            System.out.println("Booo! ");
        }
        return false;
    }


    public final void storePass() {
        System.out.println("Saving password as " + this.encryptedPass);
    }

    private int encryptDecrypt(int password) {
        return password ^ key;
    }
}
