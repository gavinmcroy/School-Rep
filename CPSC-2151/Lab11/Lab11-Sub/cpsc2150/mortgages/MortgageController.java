package cpsc2150.mortgages;

public class MortgageController implements IMortgageController {


    /* Checks if data entered is valid */
    /* MortgageView -> view */
    /* Mortgage and Customer -> model */
    /* Alerts through view if entered input is invalid */

    private final IMortgageView mortgageView;

    MortgageController(IMortgageView mV) {
        mortgageView = mV;
    }


    public void submitApplication() {
        IMortgage mortgage;
        ICustomer customer;
        final int MAX_CREDIT_SCORE = 850;

        boolean anotherCustomer = true;

        while (anotherCustomer) {
            boolean anotherMortgage = true;

            System.out.flush();
            String name = mortgageView.getName();
            double yearlyIncome = mortgageView.getYearlyIncome();

            /* If any of the user input violates the contracts specified ask for it again */
            while (yearlyIncome < 0) {
                mortgageView.printToUser("Income must be greater than 0");

                yearlyIncome = mortgageView.getYearlyIncome();
            }

            double monthlyDebtPayments = mortgageView.getMonthlyDebt();
            while (monthlyDebtPayments < 0) {
                mortgageView.printToUser("Debt must be greater than or equal to 0");
                monthlyDebtPayments = mortgageView.getMonthlyDebt();
            }

            int creditScore = mortgageView.getCreditScore();
            while (creditScore >= MAX_CREDIT_SCORE || creditScore < 0) {
                mortgageView.printToUser("Credit Score must be greater than 0 and less than 850");
                creditScore = mortgageView.getCreditScore();
            }
            while (anotherMortgage) {
                double houseCost = mortgageView.getHouseCost();
                while (houseCost < 0) {
                    mortgageView.printToUser("Cost must be greater than 0");
                    houseCost = mortgageView.getHouseCost();
                }

                double downPayment = mortgageView.getDownPayment();
                while (downPayment < 0 || (downPayment > houseCost)) {
                    mortgageView.printToUser("Down payment must be greater than 0 and less than the cost of the house.");
                    downPayment = mortgageView.getDownPayment();
                }

                int years = mortgageView.getYears();
                while (years < 0) {
                    mortgageView.printToUser("Years must be greater than 0");
                    years = mortgageView.getYears();
                }

                customer = new Customer(monthlyDebtPayments, yearlyIncome, creditScore, name);
                mortgage = new Mortgage(houseCost, downPayment, years, customer);

                mortgageView.displayCustomer(customer);
                mortgageView.displayMortgage(mortgage);

                anotherMortgage = mortgageView.getAnotherMortgage();
            }
            anotherCustomer = mortgageView.getAnotherCustomer();
        }
    }
}
