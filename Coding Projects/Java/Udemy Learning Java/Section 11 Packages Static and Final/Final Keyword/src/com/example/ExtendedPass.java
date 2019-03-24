package com.example;

public class ExtendedPass extends Password {

    private int decryptedPass;

    public ExtendedPass(int encryptedPass) {
        super(encryptedPass);
        this.decryptedPass = encryptedPass;
    }

//    @Override
//    public void storePass() {
//        System.out.println("Saving password as "+this.decryptedPass);
//    }
}
