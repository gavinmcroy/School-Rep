package com.company;

import java.util.Scanner;

public class Main {

    private static Scanner scanner = new Scanner(System.in);
    private static Button buttonPrint = new Button("Print");

    public static void main(String[] args) {
//        GearBox mclaren = new GearBox(6);
////        mclaren.addGear(1,5.3);
////        mclaren.addGear(2,10.6);
////        mclaren.addGear(3,15.9);
//        mclaren.operateClutch(true);
//        mclaren.changeGear(1);
//        mclaren.operateClutch(false);
//        System.out.println(mclaren.wheelSpeed(1000));
//        mclaren.changeGear(2);
//        System.out.println(mclaren.wheelSpeed(3000));
//        mclaren.operateClutch(true);
//        mclaren.changeGear(3);
//        mclaren.operateClutch(false);
//        System.out.println(mclaren.wheelSpeed(6000));

        class ClickListener implements Button.OnClickListener {
            public ClickListener() {
                System.out.println("Ive been attached");
            }

            @Override
            public void onClick(String title) {
                System.out.println(title + " was clicked");
            }
        }
        buttonPrint.setOnClickListener(new ClickListener());
        listen();
    }

    private static void listen() {
        boolean quit = false;
        while (!quit) {
            int choice = scanner.nextInt();
            scanner.nextLine();
            switch (choice) {
                case 0:
                    System.out.println("Ending");
                    quit = true;
                    break;
                case 1:
                    buttonPrint.click();
            }
        }
    }
}
