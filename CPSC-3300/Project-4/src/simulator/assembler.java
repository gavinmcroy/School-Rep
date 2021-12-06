package simulator;

import java.util.Scanner;
import java.io.*;

public class assembler {
    public static void main(String[] args) throws IOException {
        File infile = new File("simulator/input.asm");
        Scanner in = new Scanner(infile);
        FileOutputStream fos = new FileOutputStream("simulator/output.bin");
        DataOutputStream bos = new DataOutputStream(fos);

        while (in.hasNextLine()) {
            String comm = in.nextLine();
            String[] command = split_line(comm);

            switch (command[0]) {
                case "add":
                case "sub":
                case "AND":
                case "OR":
                case "slt": {
                    int converted = rType(command);
                    bos.writeInt(converted);
                    break;
                }
                case "lw":
                case "sw": {
                    int converted = lw_swType(command);
                    bos.writeInt(converted);
                    break;
                }
                case "beq": {
                    int converted = branch(command);
                    bos.writeInt(converted);
                    break;
                }
                case "j": {
                    int converted = jump(command);
                    bos.writeInt(converted);
                    break;
                }
            }
        }
        fos.close();
    }

    private static int rType(String[] cmd) {
        int funct, converted_rs, converted_rt, converted_rd, rs_, rt_, rd_;
        int comm = 0b0;
        String rs = (cmd[2]);
        String rt = (cmd[3]);
        String rd = (cmd[1]);

        converted_rs = registerConvert(rs);
        converted_rt = registerConvert(rt);
        converted_rd = registerConvert(rd);

        funct = functConverter(cmd[0]);

        rs_ = comm | converted_rs;
        comm = rs_ << 5;
        rt_ = converted_rt | comm;
        comm = rt_ << 5;
        rd_ = comm | converted_rd;
        comm = rd_ << 11;

        return comm | funct;
    }

    private static int lw_swType(String[] cmd) {
        int funct, converted_rs, converted_rt, lw_, sw_, lw, sw, rs_, rt_, offset;
        //Splitting Address from rs
        int comm = 0b0;

        String toBeSplit = (cmd[2]);
        String[] split = split_lw_or_sw(toBeSplit);
        String rs = (split[1]);

        converted_rs = registerConvert(rs);
        String address = (split[0]);

        offset = Integer.decode(address);

        String rt = (cmd[1]);
        converted_rt = registerConvert(rt);

        if (cmd[0].equals("lw")) {
            lw = 0b100011;
            lw_ = comm | lw;
            comm = lw_ << 5;
        } else {
            sw = 0b101011;
            sw_ = comm | sw;
            comm = sw_ << 5;
        }

        rs_ = comm | converted_rs;
        comm = rs_ << 5;
        rt_ = comm | converted_rt;
        comm = rt_ << 16;
        funct = comm | offset;
        return funct;
    }

    private static int branch(String[] cmd) {
        int funct, converted_rs, converted_rt, sw_, rs_, rt_, offset;
        int comm = 0b0;
        int beq = 0b000100;
        String rs, rt, address;

        rs = (cmd[1]);
        rt = (cmd[2]);
        address = (cmd[3]);

        converted_rs = registerConvert(rs);
        converted_rt = registerConvert(rt);

        offset = Integer.decode(address);

        sw_ = comm | beq;
        comm = sw_ << 5;
        rs_ = comm | converted_rs;
        comm = rs_ << 5;
        rt_ = comm | converted_rt;
        comm = rt_ << 16;
        funct = comm | offset;

        return funct;
    }

    private static int jump(String[] cmd) {
        int offset;
        int funct = 0b000010;
        funct = funct << 26;
        String address = (cmd[1]);

        offset = Integer.decode(address);

        funct = funct | offset;
        return funct;

    }

    private static int functConverter(String funct) {
        switch (funct) {
            case "add":
                return 0b100000;
            case "sub":
                return 0b100010;
            case "AND":
                return 0b100100;
            case "OR":
                return 0b100101;
            case "slt":
                return 0b101010;
        }
        return 0b0;
    }

    private static int registerConvert(String input) {
        switch (input) {
            case "$v0":
            case "$v0,":
                return 0b00010;
            case "$v1":
            case "$v1,":
                return 0b00011;
            case "$a0":
            case "$a0,":
                return 0b00100;
            case "$a1":
            case "$a1,":
                return 0b00101;
            case "$a2":
            case "$a2,":
                return 0b00110;
            case "$a3":
            case "$a3,":
                return 0b00111;
            case "$t0":
            case "$t0,":
                return 0b01000;
            case "$t1":
            case "$t1,":
                return 0b01001;
            case "$t2":
            case "$t2,":
                return 0b01010;
            case "$t3":
            case "$t3,":
                return 0b01011;
            case "$t4":
            case "$t4,":
                return 0b01100;
            case "$t5":
            case "$t5,":
                return 0b01101;
            case "$t6":
            case "$t6,":
                return 0b01110;
            case "$t7":
            case "$t7,":
                return 0b01111;
            case "$s0":
            case "$s0,":
                return 0b10000;
            case "$s1":
            case "$s1,":
                return 0b10001;
            case "$s2":
            case "$s2,":
                return 0b10010;
            case "$s3":
            case "$s3,":
                return 0b10011;
            case "$s4":
            case "$s4,":
                return 0b10100;
            case "$s5":
            case "$s5,":
                return 0b10101;
            case "$s6":
            case "$s6,":
                return 0b10110;
            case "$s7":
            case "$s7,":
                return 0b10111;
            case "$t8":
            case "$t8,":
                return 0b11000;
            case "$t9":
            case "$t9,":
                return 0b11001;
            case "$k0":
            case "$k0,":
                return 0b11010;
            case "$k1":
            case "$k1,":
                return 0b11011;
            default:
                return 0b0;
        }
    }

    private static String[] split_line(String command) {
        return command.split(" ");
    }

    private static String[] split_lw_or_sw(String cmd) {
        return cmd.split("[()]");
    }
}
