package simulator;

public class InstructionMemory {

    private int[] values;
    private int[] offset;
    private int PC;

    public InstructionMemory() {

    }

    public int get_PC() {
        return PC;
    }

    public void read(int[] input) {
        int length = input.length;
        this.values = new int[length];

        System.arraycopy(input, 0, this.values, 0, input.length);
        this.offset = new int[length + 1];

        for (int i = 0; i < this.offset.length - 1; i++) {
            this.offset[i] = i * 4;
        }
        this.offset[length] = -1;

    }

    public void branching(int location) {
        PC = PC + location;
    }

    public int next() {
        int next = -1;

        if (PC == 0) {
            next = this.values[0];
        } else if (this.offset[(PC / 4)] != -1) {
            next = this.values[PC / 4];
        }

        PC +=4;
        return next;
    }

    public int checkForEnd() {
        if (this.offset[(PC / 4)] == -1) {
            return -1;
        } else {
            return 0;
        }
    }
}
