package cpsc2150.mortgages;

/**
 * This interface specifiec the functionality required by the view for our mortgage application program
 * There are very few contracts as the view does not do any sort of input validation, it just
 * interacts with the user.
 *
 * Defines: Controller: The IMortgageController associated with this view
 */
public interface IMortgageView {

    /**
     *
     * @param c the Controller object
     * @pre c != NULL
     * @post = Controller = c
     */
    void setController(IMortgageController c);

    /**
     *
     * @return the house cost provided by the user
     */
    double getHouseCost();

    /**
     *
     * @return the down payment provided by the user
     */
    double getDownPayment();

    /**
     *
     * @return the years provided by the user
     */
    int getYears();

    /**
     *
     * @return the monthly debt provided by the user
     */
    double getMonthlyDebt();

    /**
     *
     * @return the income provided by the user
     */
    double getYearlyIncome();

    /**
     *
     * @return the credit score provided by the user
     */
    int getCreditScore();

    /**
     *
     * @return the name provided by the user
     */
    String getName();

    /**
     *
     * @param s the message to provide to the user
     */
    void printToUser(String s);

    /**
     * displays information about the mortgage
     * @param m, IMortgage object
     */
    void displayMortgage(IMortgage m);

    /**
     * displays information about the mortgage
     * @param c, ICustomer object
     */
    void displayCustomer(ICustomer c);

    /**
     *
     * @return whether or not the user would like to apply for another mortgage with the same customer
     */
    boolean getAnotherMortgage();

    /**
     *
     * @return whether or not the user would like to enter another customer
     */
    boolean getAnotherCustomer();
}
