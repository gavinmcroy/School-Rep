package simulator;

public class ALU {

    public ALU() {

    }

    public int compute(int value1, int value2, String operation) {

        int result = 0;

        if (operation.equals("100000")) {
            result = value1 + value2;
        }
        if (operation.equals("100010")) {
            result = value1 - value2;
        }
        if (operation.equals("100100")) {
            result = value1 & value2;
        }
        if (operation.equals("100101")) {
            result = value1 | value2;
        }
        if (operation.equals("101010")) { //set less than, honestly I dont know what this does
            result = 0;
        }

        return result;
    }

}
