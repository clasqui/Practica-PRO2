OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x


program.exe: program.o Cromosoma.o Especie.o Individu.o Poblacio.o Arbre.o PRO2Excepcio.o
	g++ -o program.exe program.o Cromosoma.o Especie.o Individu.o Poblacio.o Arbre.o PRO2Excepcio.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Especie.o: Especie.cc
	g++ -c Especie.cc $(OPCIONS)

Cromosoma.o: Cromosoma.cc
	g++ -c Cromosoma.cc $(OPCIONS)

Poblacio.o: Poblacio.cc
	g++ -c Poblacio.cc $(OPCIONS)

Individu.o: Individu.cc
	g++ -c Individu.cc $(OPCIONS)

Arbre.o: Arbre.cc
	g++ -c Arbre.cc $(OPCIONS)

PRO2Excepcio.o: PRO2Excepcio.cc
	g++ -c PRO2Excepcio.cc $(OPCIONS)


#
# Aquesta opció permet netejar el directori dels arxius
# creats durant la compilcació, .o i .exe
#
clean:
	rm *.o
	rm *.exe
