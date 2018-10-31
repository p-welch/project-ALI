
#include <iostream>
#include <fstream>
// #include <ifstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
//#include "header.h"
#include "machineheader.h"
#include "salheader.h"

/* 
 Patrick Welch
 UIC
 CS 474 
 NetID: welch9

*/

using namespace std;



bool FileExists(string filename)
{
	ifstream file(filename);
	return file.good();
}

// vector<string> ReadFile(string filename)
// {
// 	vector<string> salInstructions = vector<String>;

// }

// vector<string> ReadFromFile(string filename)
// {
// 	vector<string> instructions;

// 	fstream file;
// 	file.open(filename);
// 	string line;
// 	// getline(file, line);
// 	while(!file.eof()){
// 		getline(file, line);
// 		// line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
// 		// line = line + " ";
// 		instructions.push_back(line);
// 	}
// 	return instructions;

// }

vector<vector<string>> ReadFromFile2(string filename)
{
	vector<vector<string>> instructions;

	fstream file;
	file.open(filename);
	string line;
	// getline(file, line);
	while(!file.eof()){
		getline(file, line);
		vector<string> parameters;

		istringstream iss(line);
		string s;
		while (getline( iss, s, ' ')){
			parameters.push_back(s);
		}

		// for(string s : iss >> line){
		// 	parameters.push_back(s);
		// }

		instructions.push_back(parameters);
	}
	return instructions;

}

vector<vector<string>> ReadFromFile(string filename)
{
	vector<vector<string>> instructions;

	fstream file;
	file.open(filename);
	string line;
	// getline(file, line);
	while(!file.eof()){
		getline(file, line);
		vector<string> parameters;
		std::istringstream iss(line);
		
		parameters.insert(parameters.end(), std::istream_iterator<std::string>(iss),
		std::istream_iterator<std::string>());


		//parameters.push_back(s);
		// for(string s : iss >> line){
		// 	parameters.push_back(s);
		// }

		instructions.push_back(parameters);
	}
	return instructions;

}






int main(int argc, char **argv)
{

	vector<string> test;
	test.push_back("DEC ");
	test.push_back("SUM ");
	string symbol = test.at(1);

	map<string, int> symbolTable;
	symbolTable.insert(std::make_pair(symbol, 0));


	std::map<string, int>::iterator it;
	for (it = symbolTable.begin(); it != symbolTable.end(); ++it)
	{
		std::cout << "Symbol: " << it->first << " at location " << it->second;
	}
	std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";



	// vector<string> instructionStrings;
	// vector<vector<string>> instructionStrings2;

	// string filename = "input.sal";
	// bool programReady = false;

	// if (FileExists(filename)){
	// 	// instructionStrings = ReadFromFile(filename);
	// 	instructionStrings2 = ReadFromFile2(filename);
	// }

	// cout << "Hello world!" << endl;
	// for (auto x : instructionStrings2)
	// {
	// 	cout << "New Line" << endl;
	// 	for (auto y : x)
	// 	{
	// 		cout << y << endl;
	// 	}
	// 	cout << "End Line" << endl;
	// 	//cout << x << endl;

	// }

	// //debug
	// //Machine temp;
	// Machine temp = Machine(instructionStrings2);
	// //temp.PrintState();
	// temp.PrintCommands();
	// temp.singleInstruction();
	// //temp.PrintState();
	// temp.PrintCommands();



	// map<string, int> testMap;
	// int value = 1;
	// testMap["wooo"] = value;

	// testMap.insert(std::make_pair("woot", 2));

	// auto it = testMap.find("woot");
	// if (it != testMap.end())
	// {
	// 	cout << "testIterator: " << it->second << endl;
	// }

	// cout << "testMap: " << testMap.find("woo")->second << endl;
	// cout << "testMap: " << testMap.find("woot")->second << endl;

	// cout << "Hello world!" << endl;
	// cout << filename << endl;

	Machine *machineState = NULL;

	string line;


	cout << "\nPlease enter one of the following commands: \n";
	cout << "'i' to read instructions from file 'input.sal'" << endl;
	cout << "'r' to run through all instructions" << endl;
	cout << "'d' to run through one instruction at a time" << endl;
	cout << "'s' to save current machine state to 'output.txt'" << endl;
	cout << "'q' to quit program" << endl;

	getline(cin, line);
	char input = line[0];

	while (input != 'q')
	{
		//read all


		if (input == 'i')
		{
			string filename = "input.sal";

			if (machineState != NULL)
			{
				delete machineState;
			}

			if (FileExists(filename)){
				vector<vector<string>> instructionStrings;

				instructionStrings = ReadFromFile(filename);
				
				//debug
				for (auto x : instructionStrings)
				{
					cout << "New Line" << endl;
						for (auto y : x)
						{
							cout << y << endl;
						}
					cout << "End Line" << endl;
				}
					//cout << x << endl;



				machineState = new Machine(instructionStrings);
				machineState->PrintState();
				machineState->PrintCommands();
			}

		}

		else if (input == 'r')
		{
//check null
			if (machineState != NULL)
			{
				machineState->allInstructions();
				machineState->PrintState();
			}
			else
			{
				cout << "\nPlease read from a file first..." << endl;
			}

		}

		else if (input == 'd')
		{


			if (machineState != NULL)
			{
				machineState->singleInstruction();
				machineState->PrintState();
			}
			else
			{
				cout << "\nPlease read from a file first..." << endl;
			}

		}

		else if (input == 's')
		{
			cout << "\nSaving current instruciton list and machine state..." << endl;
			machineState->SaveState("output.txt");

		}






		cout << "\nPlease enter next command (i, r, d, s) to continue or (q) to stop...\n";


		getline(cin, line);
		input = line[0];

	}

	if (machineState != NULL)
	{
		delete machineState;
	}

	cout << "\n Exiting program... \n";













	return 0;
}

