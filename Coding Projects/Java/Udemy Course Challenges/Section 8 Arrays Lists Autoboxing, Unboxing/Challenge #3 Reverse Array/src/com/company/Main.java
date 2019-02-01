package com.company;

import java.util.Arrays;

public class Main {

    public static void main(String[] args) {
        int[] array = {1,3,5,7};
        reverseArray(array);
    }

    private static void reverseArray(int[] array){
        System.out.println("Before--> "+Arrays.toString(array));
        int lastVal = array.length-1;
        boolean cont = true;
        for(int i = 0;i<array.length;i++){
            if(lastVal>=i  && cont){
                int temp = array[i];
                array[i]=array[lastVal];
                array[lastVal]=temp;
                lastVal--;
            }else{
                cont=false;
            }
        }
        System.out.println("After-->"+Arrays.toString(array));
    }
}
