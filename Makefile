OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x


program.exe: program.o Cromosoma.o Experiment.o Individu.o Tret.o BinTree.o Familia.o
	g++ -o program.exe program.o Experiment.o Cromosoma.o Tret.o Individu.o BinTree.o Familia.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Experiment.o: Experiment.cc
	g++ -c Experiment.cc $(OPCIONS)

Cromosoma.o: Cromosoma.cc
	g++ -c Cromosoma.cc $(OPCIONS)

Tret.o: Tret.cc
	g++ -c Tret.cc $(OPCIONS)

Individu.o: Individu.cc
	g++ -c Individu.cc $(OPCIONS)

Familia.o: Familia.cc
	g++ -c Familia.cc $(OPCIONS)

BinTree.o: BinTree.cc
	g++ -c BinTree.cc $(OPCIONS)


#
# Aquesta opció permet netejar el directori dels arxius
# creats durant la compilcació, .o i .exe
#
clean:
	rm *.o
	rm *.exe
