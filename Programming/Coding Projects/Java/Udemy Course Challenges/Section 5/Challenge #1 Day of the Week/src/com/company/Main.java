package com.company;

public class Main {

    public static void main(String[] args) {
	    dayOfTheWeek(4);
	    garboDayOfTheWeek(4);
    }
    public static void dayOfTheWeek (int week){
        switch(week){
            case 1:
                System.out.println("Monday");
                break;
            case 2:
                System.out.println("Tuesday");
                break;
            case 3:
                System.out.println("Wed");
                break;
            case 4:
                System.out.println("Thursday");
                break;
            case 5:
                System.out.println("Friday");
                break;
            case 6:
                System.out.println("Saturday");
                break;
            case 7:
                System.out.println("Sunday");
                break;
            default:
                System.out.println("Invalid data ");
                break;
        }
    }
    public static void garboDayOfTheWeek(int week){
        if(week==0){
            System.out.println("Monday! ");
        }else if (week==1){
            System.out.println("Tuesday! ");
        }else if (week==3){
            System.out.println("Wed ! ");
        }else if (week==4){
            System.out.println("Thursday!");
        }else if (week==5){
            System.out.println("Friday! ");
        }else if (week==6){
            System.out.println("Saturday! ");
        }else if (week==7){
            System.out.println("Sunday! ");
        }else{
            System.out.println("Invalid data");
        }
    }
}
