package cpsc2150.mortgages;

import java.util.Scanner;
import java.lang.*;

public class MortgageView implements IMortgageView {

    private IMortgageController controller;
    private Scanner scanner = new Scanner(System.in);


    public void setController(IMortgageController c) {
        controller = c;
    }

    public double getHouseCost() {
        System.out.println("How much does the house cost?");

        return scanner.nextDouble();
    }

    public double getDownPayment() {
        System.out.println("How much is the down payment?");
        return scanner.nextDouble();
    }

    public int getYears() {
        System.out.println("How many years?");
        return scanner.nextInt();
    }

    public double getMonthlyDebt() {
        System.out.println("How much are your monthly debt payments?");
        return scanner.nextDouble();
    }

    public double getYearlyIncome() {
        System.out.println("How much is your yearly income?");
        return scanner.nextDouble();
    }

    public int getCreditScore() {
        System.out.println("What is your credit score?");
        return scanner.nextInt();
    }

    public String getName() {
        System.out.println("What's your name?");
        return scanner.nextLine();
    }

    public void printToUser(String s) {
        System.out.println(s);
    }

    public void displayMortgage(IMortgage m){
        System.out.println("Mortgage info:");
        System.out.println(m.toString());
    }

    public void displayCustomer(ICustomer c){
        System.out.println("Customer info:");
        System.out.println(c.toString());
    }

    public boolean getAnotherMortgage() {
        char response = 'o';
        while ((response != 'Y') && (response != 'N')) {
            System.out.println("Would you like to apply for another mortgage? Y/N");
            response = scanner.next().charAt(0);
            response = Character.toUpperCase(response);
        }
        String temp = scanner.nextLine();
        return response == 'Y';
    }

    public boolean getAnotherCustomer() {
        char response = 'o';
        while ((response != 'Y') && (response != 'N')) {
            System.out.println("Would you like to consider another customer? Y/N");
            response = scanner.next().charAt(0);
            response = Character.toUpperCase(response);
        }
        String temp = scanner.nextLine();
        return response == 'Y';
    }
}
