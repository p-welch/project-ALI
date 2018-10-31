//Machine.cpp
#include "machineheader.h"

Machine::Machine(std::vector<std::vector<std::string>> instructions)
: overflowBit(0), zeroBit(0), programCounter(0), regA(0), regB(0), halt(false), symbolTable(), memIndex(0), memory()
{
	// SAL memory[265];
	// int overflowBit;
	// int zeroBit;
	// int programCounter;
	// short int regA;
	// short int regB;
	//memory = new SAL[256];
	memory = new SAL*[256]();

	for (auto x : instructions)
	{
		createInstruction(x);
	}


}

Machine& Machine::operator=(const Machine& other)
{
	overflowBit = other.overflowBit;
	zeroBit = other.zeroBit;
	programCounter = other.programCounter;
	regA = other.regA;
	regB = other.regB;
	memory = new SAL*[256]();
	for (int i = 0; i < 256; i++)
	{
		memory[i] = other.memory[i];
	}
	return *this;
}

Machine::~Machine()
{
	for (int i = 0; i < 256; i++)
	{
		if (memory[i]!= NULL)
			delete memory[i];
	}
	delete[] memory;


}

void Machine::SaveState(string filename)
{

	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::trunc);



	file << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	file << "ProgramCounter: " << programCounter << endl;
	if (memory[programCounter] != NULL)
	{
		std::vector<std::string> t = memory[programCounter]->getParameters();
		file << " Next Instruction: ";
		for (auto x : t)
		{
			file << x;
			file << " ";
		}
		file << endl;
		//std::cout << "Current Instruction: " << memory[programCounter]->PrintParameters();
	}
	else
	{
		file << "Current instruction: INVALID" << endl;
	}
	
	file << "overflowBit: " << overflowBit << endl;
	file << "zeroBit: " << zeroBit << endl;
	file << "regA: " << regA << endl;
	file << "regB: " << regB << endl;
	file << "\nSymbolTable: " << endl;

	std::map<string, int>::iterator it;
	for (it = symbolTable.begin(); it != symbolTable.end(); ++it)
	{
		file << "Symbol: " << it->first << " at location " << it->second << " stores " << 
		memory[it->second]->getValue()<< endl;
	}

	file << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n";


	file << "Instruction list: " << endl;
	for (int i = 0; i < memIndex; i++)
	{
		std::vector<std::string> t = memory[i]->getParameters();
		file << "Instruction: " << i << " " << endl;
		file << "  ";
		for (auto x : t)
		{
			file << x;
			file << " ";
		}
		file << endl;
	}
	file << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";



	file.close();



}

void Machine::PrintState()
{
	std::cout << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	std::cout << "ProgramCounter: " << programCounter << endl;
	if (memory[programCounter] != NULL)
	{
		std::vector<std::string> t = memory[programCounter]->getParameters();
		std::cout << " Current Instruction: ";
		for (auto x : t)
		{
			cout << x;
			cout << " ";
		}
		std::cout << endl;
		//std::cout << "Current Instruction: " << memory[programCounter]->PrintParameters();
	}
	else
	{
		std::cout << "Current instruction: INVALID" << endl;
	}
	std::cout << "overflowBit: " << overflowBit << endl;
	std::cout << "zeroBit: " << zeroBit << endl;
	std::cout << "regA: " << regA << endl;
	std::cout << "regB: " << regB << endl;
	std::cout << "\nSymbolTable: " << endl;

	std::map<string, int>::iterator it;
	for (it = symbolTable.begin(); it != symbolTable.end(); ++it)
	{
		std::cout << "Symbol: " << it->first << " at location " << it->second << " stores " << 
		memory[it->second]->getValue()<< endl;
	}

	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";

}

void Machine::PrintCommands()
{
	std::cout << "\n\n++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	std::cout << "Instruction list: " << endl;
	for (int i = 0; i < memIndex; i++)
	{
		std::vector<std::string> t = memory[i]->getParameters();
		std::cout << "Instruction: " << i << " " << endl;
		std::cout << "  ";
		for (auto x : t)
		{
			cout << x;
			cout << " ";
		}
		std::cout << endl;
	}
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	// std::cout << "ProgramCounter: " << programCounter << endl;
	// std::cout << "TODO: current instruction" << endl;
	// std::cout << "overflowBit: " << overflowBit << endl;
	// std::cout << "zeroBit: " << zeroBit << endl;
	// std::cout << "regA: " << regA << endl;
	// std::cout << "regB: " << regB << endl;


}


void Machine::commandADD()
{
	int temp = regA + regB;
	//if (temp > SHRT_MAX || temp < SHRT_MIN)
	if (temp > SHRT_MAX || temp < SHRT_MIN)
	{
		overflowBit = 1;
	}
	else
	{
		if (temp == 0)
		{
			zeroBit = 1;
		}
		else
		{
			zeroBit = 0;
		}
	}

	regA = regA + regB;
	programCounter = programCounter + 1;
}

void Machine::commandDEC(std::string symbol)
{
	//std::make_pair newEntry(symbol, programCounter);
	//symbolTable.insert(std::make_pair(symbol, programCounter));
	symbolTable[symbol] = programCounter;
	memory[programCounter]->setValue(0);
	programCounter = programCounter + 1;
}


void Machine::commandHLT()
{
	halt = true;
	//programCounter = programCounter + 1;

}

void Machine::commandJMP(int location)
{
	programCounter = location;
}

void Machine::commandJVS(int location)
{
	if (overflowBit == 1)
	{
		programCounter = location;
	}
	else
	{
		//advance counter?
		programCounter = programCounter + 1;
	}
}
void Machine::commandJZS(int location)
{
	if (zeroBit == 1)
	{
		programCounter = location;
	}
	else
	{
		//advance counter?
		programCounter = programCounter + 1;
	}
}

void Machine::commandLDA(std::string symbol)
{
	int index = -1;
	std::map<string, int>::iterator it;
	it = symbolTable.find(symbol);
	if (it != symbolTable.end())
	{
		index = symbolTable.find(symbol)->second;
	}

	//CHECK! if greater than negative 1!!
	// if (memory[index].getValue())
	// {

	// }
	regA = memory[index]->getValue();
	//cout << "DEBUG LDA index: " << index << endl;
	//need ot get a value
	//regA = memory[index].getValue();

	programCounter = programCounter + 1;
}

void Machine::commandLDB(std::string symbol)
{
	int index = -1;
	std::map<string, int>::iterator it;
	it = symbolTable.find(symbol);
	if (it != symbolTable.end())
	{
		index = symbolTable.find(symbol)->second;
	}

	//CHECK!
	regB = memory[index]->getValue();
	//cout << "DEBUG LDA index: " << index << endl;
	//need ot get a value
	//regB = memory[index].getValue();

	programCounter = programCounter + 1;
}
void Machine::commandLDI(short int value)
{
	regA = value;
	programCounter = programCounter + 1;
}

void Machine::commandST(std::string symbol)
{
	int location = 0;
	//int index = -1;
	std::map<string, int>::iterator it;
	it = symbolTable.find(symbol);
	if (it != symbolTable.end())
	{
		location = symbolTable.find(symbol)->second;
	}
	else
	{
		cout << "ERROR: ST not found..." << endl;
		halt = true;
		return;
	}

	memory[location]->setValue(regA);

	//regA = memory[location].getValue()?

	programCounter = programCounter + 1;
}
void Machine::commandXCH()
{
	short int temp;
	temp = regA;
	regA = regB;
	regB = temp;
	programCounter = programCounter + 1;
}

void Machine::createInstruction(std::vector<std::string> parameters)
{
	std::string type;
	type = (parameters.front());
	//cout << "TYPE == " << type << "!" << endl;

	if (type == "DEC")
	{
		//cout << "Made DEC" << endl;
		memory[memIndex] = new salDEC(parameters, this);
		memIndex++;
	}

	else if (type == "LDA")
	{
		//cout << "Made LDA" << endl;
		memory[memIndex] = new salLDA(parameters, this);
		memIndex++;
	}

	else if (type == "LDB")
	{
		//cout << "Made LDB" << endl;
		memory[memIndex] = new salLDB(parameters, this);
		memIndex++;
	}

	else if (type == "LDI")
	{
		//cout << "Made LDI" << endl;
		memory[memIndex] = new salLDI(parameters, this);
		memIndex++;		
	}

	else if (type == "ST")
	{
		//salST temp = new salST(parameters, this);
		// salST* temp = new salST(parameters, this);
		//cout << "Made ST" << endl;
		memory[memIndex] = new salST(parameters, this);
		memIndex++;
		//memoryVector.push_back(temp);
	}

	else if (type == "XCH")
	{
		//cout << "Made XCH" << endl;
		memory[memIndex] = new salXCH(parameters, this);
		memIndex++;
	}

	else if (type == "ADD")
	{
		//cout << "Made ADD" << endl;
		memory[memIndex] = new salADD(parameters, this);
		memIndex++;
	}
	
	else if (type == "HLT")
	{
		//cout << "Made HLT" << endl;
		memory[memIndex] = new salHLT(parameters, this);
		memIndex++;
	}

	else if (type == "JMP")
	{
		//cout << "Made HLT" << endl;
		memory[memIndex] = new salJMP(parameters, this);
		memIndex++;
	}

	else if (type == "JZS")
	{
		//cout << "Made HLT" << endl;
		memory[memIndex] = new salJZS(parameters, this);
		memIndex++;
	}

	else if (type == "JVS")
	{
		//cout << "Made HLT" << endl;
		memory[memIndex] = new salJVS(parameters, this);
		memIndex++;
	}

	else
	{
		cout << "ERROR: Instruction type not found" << endl;
	}


}

void Machine::singleInstruction()
{
	//cout << "singleInstruction";
	if (halt != true)
	{
		memory[programCounter]->execute();
	}
	else
	{
		cout << "Program has been halted..." << endl;
	}
	//cout << "after singleInstruciton";

}

void Machine::allInstructions()
{
	while (halt != true)
	{
		if (memory[programCounter]  != NULL)
		{
			memory[programCounter]->execute();
		}
		else
		{
			cout << "ERROR: null memory[programCounter]" << endl;
		}

	}
}
