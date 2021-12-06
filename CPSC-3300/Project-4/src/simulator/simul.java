package simulator;

//This is the Control

import java.io.*;

public class simul {

    private static final Model myModel = new Model();

    public static void main(String[] args) throws IOException {
        File file = new File(args[0]);
        FileInputStream fin = new FileInputStream(file);
        BufferedInputStream bin = new BufferedInputStream(fin);
        DataInputStream din = new DataInputStream(bin);

        int count = (int) (file.length() / 4);

        int[] values = new int[count];
        for (int i = 0; i < count; i++) {
            values[i] = din.readInt();
        }

        myModel.myInstructions.read(values);

        File fileData = new File(args[1]);
        FileInputStream fileInputStream = new FileInputStream(fileData);
        BufferedInputStream bufferedInputStream = new BufferedInputStream(fileInputStream);
        DataInputStream dataInputStream = new DataInputStream(bufferedInputStream);

        int countData = (int) (fileData.length() / 4);
        System.out.println("Length of File: " + countData);
        int[] dataMemory = new int[countData];

        for (int i = 0; i < countData; i++) {
            dataMemory[i] = dataInputStream.readInt();
        }

        for (int i = 0; i < countData; i++) {
            myModel.dataMem.writeMem(i * 4, dataMemory[i]);
        }

        int execute = 1;
        while (execute == 1) {
            myModel.incrementNumCycles();
            int currentInstruction = myModel.myInstructions.next();
            functionDecode(currentInstruction);
            if (myModel.myInstructions.checkForEnd() == -1) {
                execute = -1;
            }
        }

        System.out.println("Number of Cycles: " + myModel.getNumCycles());
        System.out.println("Number of ALU Uses: " + myModel.getALUUses());
        System.out.println("PC= " + myModel.myInstructions.get_PC());
        System.out.println("Memory Reads: " + myModel.dataMem.getMemoryReads());
        System.out.println("Memory Writes: " + myModel.dataMem.getMemoryWrites());
        String currentRegisters = myModel.registers.toString();
        System.out.println("--------------------");
        System.out.println("Registers");
        System.out.println("--------------------");
        System.out.println(currentRegisters);
        System.out.println("--------------------");
        System.out.println("Data Memory");
        System.out.println("--------------------");
        System.out.println("Location \t Value (Decimal)");
        myModel.dataMem.print();

    }

    public static void functionDecode(int input) {
        StringBuilder binary = new StringBuilder(Integer.toBinaryString(input));
        int instructionLength = 32;

        if (binary.length() != instructionLength) {
            int i = instructionLength - binary.length();
            for (int k = 0; k < i; k++) {
                binary.insert(0, "0");
            }
        }

        String type = binary.substring(0, 6);

        if (type.equals("000000")) {
            rType(binary.toString());
        }
        if (type.equals("000100")) {
            branchFunction(binary.toString());
        }
        if (type.equals("100011")) {
            loadFunction(binary.toString());
        }
        if (type.equals("101011")) {
            storeFunction(binary.toString());
        }

    }

    public static void loadFunction(String input) {
        String remainder = input.substring(6, 32);
        String rs = remainder.substring(0, 5);
        String rt = remainder.substring(5, 10);
        String address = remainder.substring(10, 26);

        int addressInt = Integer.parseInt(address, 2);
        int addToAddress = myModel.registers.resolveRegister(rs);
        myModel.incrementALU_Uses();
        int finalAddress = myModel.myALU.compute(addressInt, addToAddress, "100000");
        int valueInsert = myModel.dataMem.readMem(finalAddress);
        myModel.registers.setRegister(valueInsert, rt);
    }

    public static void storeFunction(String input) {
        String remainder = input.substring(6, 32);
        String rs = remainder.substring(0, 5);
        String rt = remainder.substring(5, 10);
        String address = remainder.substring(10, 26);

        int addressInt = Integer.parseInt(address, 2);
        int addToAddress = myModel.registers.resolveRegister(rs);
        myModel.incrementALU_Uses();
        int finalAddress = myModel.myALU.compute(addressInt, addToAddress, "100000");
        int value = myModel.registers.resolveRegister(rt);
        myModel.dataMem.writeMem(finalAddress, value);
    }

    public static void branchFunction(String input) {
        String rs = input.substring(6, 11);
        String rt = input.substring(11, 16);
        String address = input.substring(16, 32);

        int rsInt = myModel.registers.resolveRegister(rs);
        int rtInt = myModel.registers.resolveRegister(rt);

        myModel.incrementALU_Uses();
        int branch = myModel.myALU.compute(rsInt, rtInt, "100010");
        int newLocation = Integer.parseInt(address, 2);

        if (branch == 0) {
            myModel.myInstructions.branching(newLocation);
        }
    }

    public static void rType(String input) {
        String rs = input.substring(6, 11);
        String rt = input.substring(11, 16);
        String rd = input.substring(16, 21);
        String function = input.substring(26, 32);

        int val1 = myModel.registers.resolveRegister(rs);
        int val2 = myModel.registers.resolveRegister(rt);

        myModel.incrementALU_Uses();
        int result = myModel.myALU.compute(val1, val2, function);
        myModel.registers.setRegister(result, rd);
    }
}
