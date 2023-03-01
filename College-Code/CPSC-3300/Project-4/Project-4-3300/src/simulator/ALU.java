package simulator;

public class ALU {

    public ALU() {

    }

    public int compute(int value1, int value2, String operation) {
        int result = 0;

        if ("100100".equals(operation)) {
            result = value1 & value2;
        }
        if ("100101".equals(operation)) {
            result = value1 | value2;
        }

        if ("100000".equals(operation)) {
            result = value1 + value2;
        }
        if ("100010".equals(operation)) {
            result = value1 - value2;
        }
        return result;
    }
}
