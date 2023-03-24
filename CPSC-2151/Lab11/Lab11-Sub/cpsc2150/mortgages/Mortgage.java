package cpsc2150.mortgages;
import java.lang.Math;
/**
 * Cierra Oliveira and Gavin McRoy
 */

/**
 * @Invariants
 * payment = (rate * principal) / (1-(1+rate)^ -(numYears/12))
 *  *               0 <= rate <= 1
 *  *               0 < DToIR
 *  *               MIN_YEARS <= numYears <= MAX_YEARS
 *  *               0 < principal
 *  *               0 <= perDown < 1
 * @Correspondence
 * Payment = payment
 * Rate = rate
 * DebtToIncomeRatio = DToIR
 * Principal = principal
 * NumberOfPayments = numYears / 12
 * PercentDown = perDown
 *
 */


public class Mortgage extends AbsMortgage implements IMortgage {

    private double payment;
    private double perDown;
    private double rate;
    private double DtoIR;
    private double principal;
    private int numYears;

    /**
     * @param houseCost the cost of house
     * @param downPayment the down payment on the house
     * @param years the number of years
     * @param customer the customer
     * @pre 0 <= downPayment <= houseCost
     *      0 < houseCost
     *      MIN_YEARS <= years <= MAX_YEARS
     *      customer not NULL
     * @post perDown = downPayment / houseCost
     *       numYears = years
     *       rate = calcRate(years, perDown, customer.getCreditScore())
     *       principal = houseCost - downPayment
     *       payment = (Rate * Principal) / (1-(1+Rate)^ -years/12
     *       DToIT = (payment + customer.getMonthlyDebtPayments()) / (customer.getIncome()/12)
     */
    Mortgage(double houseCost, double downPayment, int years, ICustomer customer){
        perDown = downPayment / houseCost;
        numYears = years;
        rate = calcRate(years, perDown, customer.getCreditScore());
        principal = houseCost - downPayment;
        payment = ((rate/12) * principal) / (1 - Math.pow((1+(rate/12)), (-1*years*12)));
        DtoIR = ( payment + customer.getMonthlyDebtPayments()) / (customer.getIncome()/12);

    }

    private double calcRate(int years, double perDown, int creditScore){
        rate = BASERATE;
        if (years < MAX_YEARS){ rate += GOODRATEADD;}
        else {rate += NORMALRATEADD;}

        if (perDown < PREFERRED_PERCENT_DOWN) { rate += GOODRATEADD; }

        if (creditScore < BADCREDIT) { rate += VERYBADRATEADD;}
        else if (creditScore < FAIRCREDIT) { rate += BADRATEADD;}
        else if (creditScore < GOODCREDIT) { rate += NORMALRATEADD;}
        else if (creditScore < GREATCREDIT) { rate += GOODRATEADD;}

        return rate;
    }

    @Override
    public boolean loanApproved() {
        return rate < RATETOOHIGH && perDown > MIN_PERCENT_DOWN && DtoIR < DTOITOOHIGH;
    }

    @Override
    public double getPayment() {
        return payment;
    }

    @Override
    public double getRate() {
        return rate;
    }

    @Override
    public double getPrincipal() {
        return principal;
    }

    @Override
    public int getYears() {
        return numYears;
    }
}
