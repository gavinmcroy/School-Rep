package com.company;

public class Main {

    public static void main(String[] args) {
        System.out.println(hasSharedDigit(56,62));
    }
    public static boolean hasSharedDigit(int firstDigit,int firstDigit1){
        int lastDigit = firstDigit;
        int lastDigit1 = firstDigit1;
        if((firstDigit>=10&&firstDigit<=99) && (firstDigit1>=10&&firstDigit1<=99)){
            lastDigit %= 10;
            lastDigit1 %=10;
            firstDigit /=10;
            firstDigit1 /=10;
            System.out.println(firstDigit+" "+lastDigit);
            System.out.println(firstDigit1+" "+lastDigit1);
            if((lastDigit==lastDigit1) || (firstDigit==firstDigit1) || (lastDigit==firstDigit1)  || (lastDigit1 ==firstDigit)){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }
}
