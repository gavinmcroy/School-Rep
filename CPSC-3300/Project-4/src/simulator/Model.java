package simulator;

public class Model {

    public DataMemory dataMem = new DataMemory();
    public RegisterFile registers = new RegisterFile();
    public ALU myALU = new ALU();
    public InstructionMemory myInstructions = new InstructionMemory();
    private int numCycles = 0;
    private int ALU_Uses = 0;

    public Model() {
        new DataMemory();
        new RegisterFile();
        new ALU();
        new InstructionMemory();
    }

    public int getALU_Uses() {
        return ALU_Uses;
    }

    public void incrementNumCycles() {
        numCycles++;
    }

    public void incrementALU_Uses() {
        ALU_Uses++;
    }

    public int getNumCycles() {
        return numCycles;
    }

}
