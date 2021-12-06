package simulator;

public class InstructionMemory {

    private int[] values;
    private int[] offset;
    private int PC;

    public InstructionMemory() {
        int PC = 0;
    }

    public int get_PC() {
        return PC;
    }

    public void read(int[] input) {
        int length = input.length;
        this.values = new int[length];

        for (int i = 0; i < input.length; i++) {
            this.values[i] = input[i];
            String binary = Integer.toBinaryString(this.values[i]);
        }
        this.offset = new int[length + 1];

        for (int i = 0; i < this.offset.length - 1; i++) {
            this.offset[i] = i * 4;
        }
        this.offset[length] = -1;

    }

    public int branch(int location) {
        int newLocation = PC + location;
        int result = 0;

        for (int i = 0; i < this.offset.length; i++) {
            if (this.offset[i] == newLocation) {
                result = this.values[i];
            }
        }

        PC = newLocation;

        return result;
    }

    public void branching(int location) {
        PC = PC + location;
    }

    public int next() {
        int next = -1;

        if (PC == 0) {
            next = this.values[0];
            String binary = Integer.toBinaryString(next);
        } else if (this.offset[(PC / 4)] != -1) {
            next = this.values[PC / 4];
            String binary = Integer.toBinaryString(next);
        }

        PC = PC + 4;
        return next;
    }

    public int checkforEnd() {
        if (this.offset[(PC / 4)] == -1) {
            return -1;
        } else {
            return 0;
        }
    }
}
