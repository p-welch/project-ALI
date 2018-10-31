//machineheader.h


#ifndef MACHINEHEADER_H
#define MACHINEHEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdint>
#include <climits>
#include <vector>
#include <fstream>

#include "salheader.h"
// std::numeric_limits<std::int32_t>::max();
// std::numeric_limits<std::int32_t>::min();

using namespace std;

// # include<iostream>
class SAL;

class Machine{
	
	//memIndex (reading into memory the first time)
	//memory - for instructions
	//SAL memory[265];
	private:
		int overflowBit;
		int zeroBit;
		int programCounter;
		short int regA;
		short int regB;
		bool halt;
		std::map<string, int> symbolTable;
		//SAL memory[];
		int memIndex;
		SAL** memory;
		//std::vector<SAL> memoryVector;
		//const SAL *memory;

	public:
		Machine(std::vector<std::vector<std::string>> instructions);
		Machine& operator=(const Machine& other);
		~Machine();

		void PrintState();
		void PrintCommands();
		void SaveState(std::string filename);
		void commandADD();
		void commandDEC(std::string symbol);
		void commandHLT();
		void commandJMP(int location);
		void commandJVS(int location);
		void commandJZS(int location);
		void commandLDA(std::string symbol);
		void commandLDB(std::string symbol);
		void commandLDI(short int value);
		void commandST(std::string symbol);
		void commandXCH();

		void createInstruction(std::vector<std::string> parameters);
		void singleInstruction();
		void allInstructions();

};


#endif