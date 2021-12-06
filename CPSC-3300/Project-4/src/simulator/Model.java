package simulator;

public class Model {

    public DataMemory dataMem = new DataMemory();
    public RegisterFile registers = new RegisterFile();
    public ALU myALU = new ALU();
    public InstructionMemory myInstructions = new InstructionMemory();
    private int numCycles = 0;
    private int ALUUses = 0;

    public Model() {
        new DataMemory();
        new RegisterFile();
        new ALU();
        new InstructionMemory();
    }

    public void incrementNumCycles() {
        numCycles++;
    }

    public void incrementALU_Uses() {
        ALUUses++;
    }

    public int getNumCycles() {
        return numCycles;
    }

    public int getALUUses() {
        return ALUUses;
    }

}
