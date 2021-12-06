package simulator;

public class RegisterFile {

    private int R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15, R16, R17, R18, R19, R20, R21, R22, R23, R24, R25, R26, R27, R28, R29, R30, R31;

    public RegisterFile() {

        this.R0 = 0b0;
        this.R1 = 0b0;
        this.R2 = 0b0;
        this.R3 = 0b0;
        this.R4 = 0b0;
        this.R5 = 0b0;
        this.R6 = 0b0;
        this.R7 = 0b0;
        this.R8 = 0b0;
        this.R9 = 0b0;
        this.R10 = 0b0;
        this.R11 = 0b0;
        this.R12 = 0b0;
        this.R13 = 0b0;
        this.R14 = 0b0;
        this.R15 = 0b0;
        this.R16 = 0b0;
        this.R17 = 0b0;
        this.R18 = 0b0;
        this.R19 = 0b0;
        this.R20 = 0b0;
        this.R21 = 0b0;
        this.R22 = 0b0;
        this.R23 = 0b0;
        this.R24 = 0b0;
        this.R25 = 0b0;
        this.R26 = 0b0;
        this.R27 = 0b0;
        this.R28 = 0b0;
        this.R29 = 0b0;
        this.R30 = 0b0;
        this.R31 = 0b0;

    }

    public void set_Register(int set, String register) {
        switch (register) {
            case "00000":
                this.R0 = set;
                break;
            case "00001":
                R1 = set;
                break;
            case "00010":
                R2 = set;
                break;
            case "00011":
                R3 = set;
                break;
            case "00100":
                R4 = set;
                break;
            case "00101":
                R5 = set;
                break;
            case "00110":
                R6 = set;
                break;
            case "00111":
                R7 = set;
                break;
            case "01000":
                R8 = set;
                break;
            case "01001":
                R9 = set;
                break;
            case "01010":
                R10 = set;
                break;
            case "01011":
                R11 = set;
                break;
            case "01100":
                R12 = set;
                break;
            case "01101":
                R13 = set;
                break;
            case "01110":
                R14 = set;
                break;
            case "01111":
                R15 = set;
                break;
            case "10000":
                R16 = set;
                break;
            case "10001":
                R17 = set;
                break;
            case "10010":
                R18 = set;
                break;
            case "10011":
                R19 = set;
                break;
            case "10100":
                R20 = set;
                break;
            case "10101":
                R21 = set;
                break;
            case "10110":
                R22 = set;
                break;
            case "10111":
                R23 = set;
                break;
            case "11000":
                R24 = set;
                break;
            case "11001":
                R25 = set;
                break;
            case "11010":
                R26 = set;
                break;
            case "11011":
                R27 = set;
                break;
            case "11100":
                R28 = set;
                break;
            case "11101":
                R29 = set;
                break;
            case "11110":
                R30 = set;
                break;
            case "11111":
                R31 = set;
                break;
        }
    }

    public int resolve_Register(String binary) {
        switch (binary) {
            case "00000":
                return R0;
            case "00001":
                return R1;
            case "00010":
                return R2;
            case "00011":
                return R3;
            case "00100":
                return R4;
            case "00101":
                return R5;
            case "00110":
                return R6;
            case "00111":
                return R7;
            case "01000":
                return R8;
            case "01001":
                return R9;
            case "01010":
                return R10;
            case "01011":
                return R11;
            case "01100":
                return R12;
            case "01101":
                return R13;
            case "01110":
                return R14;
            case "01111":
                return R15;
            case "10000":
                return R16;
            case "10001":
                return R17;
            case "10010":
                return R18;
            case "10011":
                return R19;
            case "10100":
                return R20;
            case "10101":
                return R21;
            case "10110":
                return R22;
            case "10111":
                return R23;
            case "11000":
                return R24;
            case "11001":
                return R25;
            case "11010":
                return R26;
            case "11011":
                return R27;
            case "11100":
                return R28;
            case "11101":
                return R29;
            case "11110":
                return R30;
            case "11111":
                return R31;
            default:
                return 0b0;
        }

    }

    @Override
    public String toString() {
        //4x8
        return String.format("R0= " + R0 + "\tR1= " + R1 + "\tR2= " + R2 + "\tR3= " + R3 + "\n" +
                "R4= " + R4 + "\tR5= " + R5 + "\tR6= " + R6 + "\tR7= " + R7 + "\n" +
                "R8= " + R8 + "\tR9= " + R9 + "\tR10= " + R10 + "\tR11= " + R11 + "\n" +
                "R12= " + R12 + "\tR13= " + R13 + "\tR14= " + R14 + "\tR15= " + R15 + "\n" +
                "R16= " + R16 + "\tR17= " + R17 + "\tR18= " + R18 + "\tR19= " + R19 + "\n" +
                "R20= " + R20 + "\tR21= " + R21 + "\tR22= " + R22 + "\tR23= " + R23 + "\n" +
                "R24= " + R24 + "\tR25= " + R25 + "\tR26= " + R26 + "\tR27= " + R27 + "\n" +
                "R28= " + R28 + "\tR29= " + R29 + "\tR30= " + R30 + "\tR31= " + R31);


    }


}
