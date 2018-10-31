
#ifndef SALHEADER_H
#define SALHEADER_H

#include "machineheader.h"

// std::numeric_limits<std::int32_t>::max();
// std::numeric_limits<std::int32_t>::min();

using namespace std;

class Machine;

class SAL{
	public:
		SAL(){};
		virtual ~SAL(){};
		virtual void execute() = 0;
		virtual short int getValue() = 0;
		virtual void setValue(short int x) = 0;
		virtual void PrintParameters() = 0;
		virtual std::vector<std::string> getParameters() = 0;

};

class salADD : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salADD(std::vector<std::string> params, Machine* machineState);
		~salADD();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();




};

class salDEC : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salDEC(std::vector<std::string> params, Machine* machineState);
		~salDEC();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();


};

class salHLT : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salHLT(std::vector<std::string> params, Machine* machineState);
		~salHLT();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();


};

class salJMP : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salJMP(std::vector<std::string> params, Machine* machineState);
		~salJMP();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};

class salJVS : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salJVS(std::vector<std::string> params, Machine* machineState);
		~salJVS();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};

class salJZS : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salJZS(std::vector<std::string> params, Machine* machineState);
		~salJZS();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};

class salLDA : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salLDA(std::vector<std::string> params, Machine* machineState);
		~salLDA();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};

class salLDB : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salLDB(std::vector<std::string> params, Machine* machineState);
		~salLDB();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};

class salLDI : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salLDI(std::vector<std::string> params, Machine* machineState);
		~salLDI();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};


class salST : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salST(std::vector<std::string> params, Machine* machineState);
		~salST();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();




};

class salXCH : public SAL{
	private:
		bool isInstruction;
		short int value;
		std::vector<string> parameters;
		Machine* machinePtr;

	public:

		//salST(std::vector<std::string> params, const Machine& machineState);
		salXCH(std::vector<std::string> params, Machine* machineState);
		~salXCH();
		virtual void execute();
		virtual void setValue(short int x);
		virtual short int getValue();
		virtual void PrintParameters();
		virtual std::vector<std::string> getParameters();

};




// class SAL{





// };


// class subSal{




// };



#endif