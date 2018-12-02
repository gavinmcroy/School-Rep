package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(hasTeen(19,21,30));
    }
    public static boolean hasTeen(int t1,int t2, int t3){
        if((t1>=13 && t1<=19) || (t2>=13 && t2<=19) || (t3>=13 && t3<=19)){
            return true;
        }
        return false;
    }
}
