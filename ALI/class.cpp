//class.cpp

#include "header.h"


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




//---------------------------------------------------------------------
//SAL classes below

		// salST(Machine& machienState);
		// salST::~salST();
		// execute(std::vector<std::string>);
		// void setValue(short int);
		// short int getValue();

// salST::salST(std::vector<std::string> params, const Machine& machineState)

salADD::salADD(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salADD::~salADD()
{

}


void salADD::execute()
{
	machinePtr->commandADD();
	//PrintParameters();
	//cout << "DEBUG: ADD" << endl;
}

short int salADD::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salADD::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salADD::getParameters()
{
	return parameters;
}

void salADD::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////

salDEC::salDEC(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salDEC::~salDEC()
{

}


void salDEC::execute()
{

	machinePtr->commandDEC(parameters.at(1));
	//PrintParameters();
	isInstruction = false;
	//cout << "Storing symbol: ";
	//cout << parameters.at(1);
}

short int salDEC::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salDEC::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salDEC::getParameters()
{
	return parameters;
}

void salDEC::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////


salHLT::salHLT(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salHLT::~salHLT()
{

}


void salHLT::execute()
{
	machinePtr->commandHLT();
	//PrintParameters();
	//cout << "DEBUG: HLT" << endl;
}

short int salHLT::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salHLT::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salHLT::getParameters()
{
	return parameters;
}

void salHLT::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////


salJMP::salJMP(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salJMP::~salJMP()
{

}


void salJMP::execute()
{
	machinePtr->commandJMP(std::stoi(parameters.at(1)));
	//PrintParameters();
	//cout << "DEBUG: JMP" << endl;
}

short int salJMP::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salJMP::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salJMP::getParameters()
{
	return parameters;
}

void salJMP::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////

salJVS::salJVS(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salJVS::~salJVS()
{

}


void salJVS::execute()
{
	machinePtr->commandJVS(std::stoi(parameters.at(1)));
	// PrintParameters();
	//cout << "DEBUG: JVS" << endl;
}

short int salJVS::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salJVS::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salJVS::getParameters()
{
	return parameters;
}

void salJVS::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}


/////////////////////////////////


salJZS::salJZS(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salJZS::~salJZS()
{

}


void salJZS::execute()
{
	machinePtr->commandJZS(std::stoi(parameters.at(1)));
	//PrintParameters();
	//cout << "DEBUG: JZS" << endl;
}

short int salJZS::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salJZS::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salJZS::getParameters()
{
	return parameters;
}

void salJZS::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////



salLDA::salLDA(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salLDA::~salLDA()
{

}


void salLDA::execute()
{
	machinePtr->commandLDA(parameters.at(1));
	// PrintParameters();
	//cout << "DEBUG: LDA" << endl;
}

short int salLDA::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salLDA::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salLDA::getParameters()
{
	return parameters;
}

void salLDA::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////


salLDB::salLDB(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salLDB::~salLDB()
{

}


void salLDB::execute()
{
	machinePtr->commandLDB(parameters.at(1));
	// PrintParameters();
	//cout << "DEBUG: LDB" << endl;
}

short int salLDB::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salLDB::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salLDB::getParameters()
{
	return parameters;
}

void salLDB::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////


salLDI::salLDI(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salLDI::~salLDI()
{

}


void salLDI::execute()
{
	machinePtr->commandLDI(std::stoi(parameters.at(1)));
	// PrintParameters();
	//cout << "DEBUG: LDI" << endl;
}

short int salLDI::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salLDI::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salLDI::getParameters()
{
	return parameters;
}

void salLDI::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////

salST::salST(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salST::~salST()
{

}


void salST::execute()
{
	machinePtr->commandST(parameters.at(1));
	//PrintParameters();
	//cout << "DEBUG: ST" << endl;
}

short int salST::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salST::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salST::getParameters()
{
	return parameters;
}

void salST::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////

salXCH::salXCH(std::vector<std::string> params, Machine *machineState)
: isInstruction(true), value(0), parameters(params), machinePtr(machineState)
{

}

salXCH::~salXCH()
{

}


void salXCH::execute()
{
	machinePtr->commandXCH();
	// PrintParameters();
	//cout << "DEBUG: XCH" << endl;
}

short int salXCH::getValue()
{
	if (isInstruction == false)
	{
		return value;
	}

}

void salXCH::setValue(short int x)
{
	isInstruction = false;
	value = x;

}

vector<string> salXCH::getParameters()
{
	return parameters;
}

void salXCH::PrintParameters()
{
	for (auto x : parameters)
	{
		cout << x << endl;
	}

}

/////////////////////////////////