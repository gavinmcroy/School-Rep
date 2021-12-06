package simulator;

public class Model {

    public DataMemory dataMem = new DataMemory();
    public RegisterFile registers = new RegisterFile();
    public ALU myALU = new ALU();
    public InstructionMemory myInstructions = new InstructionMemory();
    private int numCycles = 0;
    private int PC = 0;
    private int ALU_Uses = 0;

    public Model(){
        DataMemory dataMem =  new DataMemory();
        RegisterFile registers = new RegisterFile();
        ALU myALU = new ALU();
        InstructionMemory myInstructions = new InstructionMemory();
        int numCycles = 0;
        int ALU_Uses = 0;
    }

    public int getALU_Uses(){
        return ALU_Uses;
    }

    public void incrementNumCycles(){
        numCycles++;
    }

    public void incrementPC(){
        PC = PC + 4;
    }

    public void changePC(int offset){
        PC = offset;
    }

    public void incrementALU_Uses(){
        ALU_Uses++;
    }

    public int getNumCycles(){
        return numCycles;
    }

    public int getPC(){
        return PC;
    }

}
