all: welch9ALI

welch9ALI: OOPwelch9project4.o Machine.o SAL.o
	g++ -std=c++11 OOPwelch9project4.o Machine.o SAL.o -o welch9ALI

OOPwelch9project4.o: OOPwelch9project4.cpp machineheader.h salheader.h
	g++ -std=c++11 OOPwelch9project4.cpp -c

Machine.o: Machine.cpp machineheader.h
	g++ -std=c++11 Machine.cpp -c

SAL.o: SAL.cpp salheader.h machineheader.h
	g++ -std=c++11 SAL.cpp -c

clean:
	rm welch9ALI OOPwelch9project4.o Machine.o SAL.o