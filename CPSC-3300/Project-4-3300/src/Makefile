all: simulator/Assembler.java simulator/simul.java simulator/InstructionMemory.java simulator/Model.java simulator/DataMemory.java simulator/ALU.java simulator/RegisterFile.java
	javac simulator/simul.java simulator/InstructionMemory.java simulator/Model.java simulator/DataMemory.java simulator/ALU.java simulator/RegisterFile.java
	javac simulator/Assembler.java

smolmips: simulator/simul.class simulator/InstructionMemory.class simulator/Model.class simulator/DataMemory.class simulator/ALU.class simulator/RegisterFile.class
	java simulator/simul output.bin memory.bin

masm: simulator/Assembler.class
	java simulator/Assembler input.asm

clean:
	rm -f simulator/*.class