run : turing_machine.exe
	@./turing_machine.exe conf.txt

build : source.o  turing_machine.o 
	g++ -o turing_machine.exe source.o  turing_machine.o
	@echo "Done."


source.o : source.cpp turing_machine.h
	@echo "Compile..."
	g++  -c source.cpp 


turing_machine.o : turing_machine.cpp turing_machine.h
	g++  -c turing_machine.cpp 

.PHONY: clean
clean : 
	@echo "Clear..."
	rm  turing_machine.exe  source.o  turing_machine.o
