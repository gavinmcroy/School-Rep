package simulator;

//This is the Control

import java.io.*;
import java.util.Scanner;

public class simul {

    private static Model myModel = new Model();

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

    for(int i = 0; i < values.length; i++){
        String binary = Integer.toBinaryString(values[i]);
    }

        File file_data = new File(args[1]);
        FileInputStream fin_data = new FileInputStream(file_data);
        BufferedInputStream bin_data = new BufferedInputStream(fin_data);
        DataInputStream din_data = new DataInputStream(bin_data);

        int count_data = (int) (file_data.length() / 4);
        System.out.println("Length of File: " + count_data);
        int[] dataMemory = new int[count_data];
        for (int i = 0; i < count_data; i++) {
            dataMemory[i] = din_data.readInt();
        }

        for(int i = 0; i < count_data; i++){
            myModel.dataMem.writeMem(i*4,dataMemory[i]);
        }

    int execute = 1;

    while(execute == 1){
        myModel.incrementNumCycles();
        int currentInstruction = myModel.myInstructions.next();
        functionDecode(currentInstruction);
        if(myModel.myInstructions.checkforEnd() == -1){
            execute = -1;
        }
    }

    //Print Everything
    System.out.println("Number of Cycles: " + myModel.getNumCycles());
    System.out.println("Number of ALU Uses: " + myModel.getALU_Uses());
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

    public static String functionDecode(int input){

        String binary = Integer.toBinaryString(input);

        if(binary.length() != 32){
            int i = 32 - binary.length();
            for(int k = 0; k < i; k++){
                binary = "0" + binary;
            }
        }

        String type = binary.substring(0,6);

        String returnType = "";

        if(type.equals("000000")){
            rtype(binary);
        }
        if(type.equals("000100")){
            branch(binary);
        }
        if(type.equals("100011")){
            load(binary);
        }
        if(type.equals("101011")){
            store(binary);
        }

        return returnType;

    }

    public static void store(String input){
        String remainder = input.substring(6,32);
        String rs = remainder.substring(0,5);
        String rt = remainder.substring(5,10);
        String address = remainder.substring(10,26);

        int addressInt = Integer.parseInt(address, 2);
        int addtoAddress = myModel.registers.resolve_Register(rs);
        myModel.incrementALU_Uses();
        int finalAddress = myModel.myALU.compute(addressInt,addtoAddress,"100000");
        int value = myModel.registers.resolve_Register(rt);
        myModel.dataMem.writeMem(finalAddress, value);
    }

    public static void load(String input){
        String remainder = input.substring(6,32);
        String rs = remainder.substring(0,5);
        String rt = remainder.substring(5,10);
        String address = remainder.substring(10,26);

        int addressInt = Integer.parseInt(address, 2);
        int addtoAddress = myModel.registers.resolve_Register(rs);
        myModel.incrementALU_Uses();
        int finalAddress = myModel.myALU.compute(addressInt,addtoAddress,"100000");
        int valueInsert = myModel.dataMem.readMem(finalAddress);
        myModel.registers.set_Register(valueInsert,rt);
    }

    public static void rtype(String input){
        String rs = input.substring(6,11);
        String rt = input.substring(11,16);
        String rd = input.substring(16,21);
        String funct = input.substring(26,32);

        int value1 = myModel.registers.resolve_Register(rs);
        int value2 = myModel.registers.resolve_Register(rt);

        myModel.incrementALU_Uses();
        int result = myModel.myALU.compute(value1,value2,funct);

        myModel.registers.set_Register(result,rd);
    }

    public static void branch(String input){
        String rs = input.substring(6,11);
        String rt = input.substring(11,16);
        String address = input.substring(16,32);

        int rsInt = myModel.registers.resolve_Register(rs);
        int rtInt = myModel.registers.resolve_Register(rt);

        myModel.incrementALU_Uses();
        int branch = myModel.myALU.compute(rsInt, rtInt, "100010");

        int newLocation = Integer.parseInt(address, 2);

        if(branch == 0){
            myModel.myInstructions.branching(newLocation);
        }

    }


}
