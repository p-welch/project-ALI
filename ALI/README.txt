README CS 474
Patrick Welch
welch9
Project #4

I structured my program using the command pattern. My project uses a class Machine to contain data about machine
state using the following: integers for programCounter, zeroBit, overflowBit, and memIndex(for first time 
instruction reading); short ints for regA and regB; a bool for halt; a map<string, int> for the symbolTable 
representation, and a pointer array (SAL** memory with 256 elements) of my abstract second class, SAL. 

The class SAL is an uninitialized abstract class with subclasses that corresponds to every command, the functionality
which is defined in the Machine class. For example, the salST has an execute() that overrides the SAL abstract class
which implements Machine::commandST(), which will accept variables from the SAL subclass as needed. Program execution
is determined on this SAL array and the program counter, used as an index. It will cease execution once the commandHLT()
is given and the halt flag is set.

The machine class reads in the SAL instructions using a vector of vector<string> in order to initialize new instances 
of the SAL subclass, which are then used by reference the pointer array in the machine class. In order to accommodate 
the ability to store values in memory where instructions can also be, each SAL subclass contains a short int value 
and a boolean isInstruction to check if an instruction has been turned into storage address. The symbol table keeps
track of these DEC entries using the map symbol table reference earlier.

To make and run the program:

type: "make all"
then: "./welch9ALI"

to remove the program and intermediaries:
type: "make clean"

The commands (i, r, d, s, q) all work as single character inputs:

1.  i — This command reads a SAL program from a ﬁle named input.sal. The ﬁle should be in the same directory as the 
executable ALI ﬁle. The program is stored in internal ALI memory and displayed on the user’s console.

2. d — Execute the program in debug mode. This command causes one line of code to be executed. The PC, registers, 
bits and the state of memory are updated as a result of the execution. The value of the registers, the PC, the bits 
and the content of memory after the instruction is executed are diplayed on the user’s screen.

3. r — Run the program to completion. This command causes the execution of program starting from the current PC instruction 
until the halt instruction is found or the program reaches its last instruction. The content of the registers, PC, bits 
and memory are displayed on the user’s console.

4. s — Save the program state. This command causes the content of memory, the bits and the registers to be saved to a ﬁle 
named output.txt.

5. q — Quits the ALI
