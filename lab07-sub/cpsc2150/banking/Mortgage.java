package cpsc2150.banking;

import java.lang.Math;
/**
 * Cierra Oliveira and Gavin McRoy
 */

/**
 * @Invariants payment = (rate * principal) / (1-(1+rate)^ -(numYears/12))
 * *               0 <= rate <= 1
 * *               0 < DToIR
 * *               MIN_YEARS <= numYears <= MAX_YEARS
 * *               0 < principal
 * *               0 <= perDown < 1
 * @Correspondence Payment = payment
 * Rate = rate
 * DebtToIncomeRatio = DToIR
 * Principal = principal
 * NumberOfPayments = numYears / 12
 * PercentDown = perDown
 */


public class Mortgage extends AbsMortgage implements IMortgage {

    private double payment;
    private double perDown;
    private double rate;
    private double DtoIR;
    private double principal;
    private int numYears;

    /**
     * @param houseCost   the cost of house
     * @param downPayment the down payment on the house
     * @param years       the number of years for the mortgage
     * @param customer    the customer we are checking
     * @pre 0 <= downPayment <= houseCost
     * 0 < houseCost
     * MIN_YEARS <= years <= MAX_YEARS
     * customer not NULL
     * @post perDown = downPayment / houseCost
     * numYears = years
     * rate = calcRate(years, perDown, customer.getCreditScore())
     * principal = houseCost - downPayment
     * payment = (Rate * Principal) / (1-(1+Rate)^ -years/12
     * DToIT = (payment + customer.getMonthlyDebtPayments()) / (customer.getIncome()/12)
     */
    Mortgage(double houseCost, double downPayment, int years, ICustomer customer) {
        perDown = downPayment / houseCost;
        numYears = years;
        rate = calcRate(years, perDown, customer.getCreditScore());
        principal = houseCost - downPayment;
        payment = ((rate / 12) * principal) / (1 - Math.pow((1 + (rate / 12)), (-1 * years * 12)));
        DtoIR = (payment + customer.getMonthlyDebtPayments()) / (customer.getIncome() / 12);

    }

    /***
     * This method calculates the rate by first checking if years
     * is more or less than the max possible years. If true we add the good rate else we
     * add the normal rate. Then we check if our perDown (ratio between down payment and house cost)
     * is lower than the preferred percent down. If so we add the good rate, else we do nothing. Next we
     * check credit and add the appropriate rate to the calculated rate depending on the credit score
     *
     * @param years the number of years to calculate for
     * @param perDown is the ratio between the down payment and house cost
     * @param creditScore the credit score
     * @return returns the calculated rate
     * @pre MIN_YEARS <= years <= MAX_YEARS  and 0 <= perDown < 1 and 0 < creditScore < 850 (Max credit score)
     * @post calcRate() = determineRate
     */
    private double calcRate(int years, double perDown, int creditScore) {
        double determineRate = BASERATE;
        if (years < MAX_YEARS) {
            determineRate += GOODRATEADD;
        } else {
            determineRate += NORMALRATEADD;
        }

        if (perDown < PREFERRED_PERCENT_DOWN) {
            determineRate += GOODRATEADD;
        }

        if (creditScore < BADCREDIT) {
            determineRate += VERYBADRATEADD;
        } else if (creditScore < FAIRCREDIT) {
            determineRate += BADRATEADD;
        } else if (creditScore < GOODCREDIT) {
            determineRate += NORMALRATEADD;
        } else if (creditScore < GREATCREDIT) {
            determineRate += GOODRATEADD;
        }

        return determineRate;
    }

    /**
     * This method will calculate if a loan is approved or if a loan is not approved
     *
     * @return returns true if the rate is less than what is classified as a rate too high and per down
     * (ratio between down payment and house cost) is greater than the minimum percentage down
     * and debt to income ratio is less than the a debt to income ratio that's too high
     */
    @Override
    public boolean loanApproved() {
        return rate < RATETOOHIGH && perDown > MIN_PERCENT_DOWN && DtoIR < DTOITOOHIGH;
    }

    /**
     * Returns the monthly payment on the mortgage
     *
     * @return returns the monthly payment on the mortgage
     */
    @Override
    public double getPayment() {
        return payment;
    }

    /**
     * Returns the interest rate per monthly period on the loan
     *
     * @return returns the rate
     */
    @Override
    public double getRate() {
        return rate;
    }

    /**
     * Returns The amount of the loan (houseCost - downPayment)
     *
     * @return returns the principal
     */
    @Override
    public double getPrincipal() {
        return principal;
    }

    /**
     * Returns the number of years left on monthly payments
     *
     * @return the number of years
     */
    @Override
    public int getYears() {
        return numYears;
    }
}
