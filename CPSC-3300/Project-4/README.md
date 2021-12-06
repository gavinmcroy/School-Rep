# Ryan Auger and Logan Ferland

How to run:
Makefile must be outside of simulator folder. Everything else including input files must be inside of the simulator folder
1. to compile both programs use make or make all
2. to run mips assembler type make masm
3. to run cpu simulator type make smolmips
4. to clean type make clean

Design Decisions:

simul.java operates as the control
- It reads in both the instruction memory and data memory files
- Control then calls different logic blocks to complete operations
the text view is printed every cycle to the command line
Model has many parts:
Model.java
- An object that initializes all logic blocks. Including:
1. InstructionMemory.java
    - Contains the PC counter, every line of code, and it's corresponding PC
2. RegisterFile.java
    - Contains values of all Registers with the ability to set and get all values
3. ALU.java
    - Contains the functionality of an ALU and counts number of times it is used
4. DataMemory.java
    - Contains our implementation of Data Memory
    - Is originally accessed by the DataMemory input file and then with all LW and SW operations
