
//---------------------------------------------------------------------
//SAL classes below

		// salST(Machine& machienState);
		// salST::~salST();
		// execute(std::vector<std::string>);
		// void setValue(short int);
		// short int getValue();

// salST::salST(std::vector<std::string> params, const Machine& machineState)
#include "salheader.h"

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