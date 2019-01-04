package com.company;

public class Main {

    public static void main(String[] args) {
        int switchValue = 4;
        switch (switchValue) {
            case 1:
                System.out.println("Value is 1");
                break;
            case 2:
                System.out.println("Value is 2");
                break;
            case 3: case 4:case 5:
                System.out.println("was 3 or 4 or 5");
                System.out.println("Actually it was "+switchValue);
                break;
            default:
                System.out.println("Was not 1 or 2");
                break;
        }
//      switchTesting();
        hyperEffectiveSwitch();
        stringBasedSwitch();
    }
    public static void switchTesting(){
        char letter = 'A';
        switch(letter){
            case 'A':
                System.out.println("Letter is "+letter);
                break;
            case 'B':
                System.out.println("Letter is "+letter);
                break;
            case 'C':
                System.out.println("Letter is "+letter);
                break;
            case 'D':
                System.out.println("Letter is "+letter);
                break;
            case 'E':
                System.out.println("Letter is "+letter);
                break;
            default:
                System.out.println("Neither A , B , C , D or E");
                break;
        }
    }
    public static void hyperEffectiveSwitch(){
        char fastLetter = 'A';
        switch(fastLetter){
            case 'A': case 'B': case 'C': case 'D': case 'E':
                System.out.println("your letter is "+fastLetter);
                break;
            default:
                System.out.println("Neither A , B , C , D or E");
        }
    }
    public static void stringBasedSwitch(){
        String month = "September";
        //---Turns string into all lower case!
        switch(month.toLowerCase()){
            case "january":
                System.out.println("Its snowing! ");
                break;
            case "september":
                System.out.println("Its hot.. :( ");
                break;
        }
    }
}
