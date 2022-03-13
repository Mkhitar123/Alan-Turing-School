

source : source.o  hugeint.o
	g++ -o source source.o  hugeint.o
	@echo "Done."


source.o : source.cpp hugeint.h
	@echo "Compile..."
	g++  -c source.cpp 


hugeint.o : hugeint.cpp hugeint.h
	g++  -c hugeint.cpp 


clean :
	@echo "Clear..."
	rm  source  source.o  hugeint.o

