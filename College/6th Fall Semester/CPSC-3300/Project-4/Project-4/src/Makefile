all: simulator/assembler.java simulator/simul.java simulator/InstructionMemory.java simulator/Model.java simulator/DataMemory.java simulator/ALU.java simulator/RegisterFile.java
	javac simulator/simul.java simulator/InstructionMemory.java simulator/Model.java simulator/DataMemory.java simulator/ALU.java simulator/RegisterFile.java
	javac simulator/assembler.java

smolmips: simulator/simul.class simulator/InstructionMemory.class simulator/Model.class simulator/DataMemory.class simulator/ALU.class simulator/RegisterFile.class
	java simulator/simul simulator/output.bin simulator/memory.bin

masm: simulator/assembler.class
	java simulator/assembler simulator/output.bin

clean:
	rm -f simulator/*.class