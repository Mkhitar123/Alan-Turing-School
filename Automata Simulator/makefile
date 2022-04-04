run : Automata.exe
	@./Automata.exe conf.txt

build : Source.o  Automata.o
	g++ -o Automata.exe Source.o  Automata.o
	@echo "Done."


Source.o : Source.cpp Automata.h
	@echo "Compile..."
	g++  -c Source.cpp 


Automata.o : Automata.cpp Automata.h
	g++  -c Automata.cpp 

.PHONY: clean
clean : 
	@echo "Clear..."
	rm  Automata.exe  Source.o  Automata.o
