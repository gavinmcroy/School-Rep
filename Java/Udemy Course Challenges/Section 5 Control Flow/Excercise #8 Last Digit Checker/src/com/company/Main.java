package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(hasSameLastDigit(14,22,42));
    }
    public static boolean hasSameLastDigit(int num1,int num2,int num3){
        if((num1>=10&&num1<=1000) && (num2>=10&&num2<=1000) && (num3>=10&&num3<=1000)){
            num1%=10;
            num2%=10;
            num3%=10;
            if((num1==num2) || (num1==num3) || (num2==num3)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
}
