all: set_calculator

set_calculator: main_set_calculator.o set_calculator.o
	g++ -std=c++14 -g -Wall -o set_calculator main_set_calculator.o set_calculator.o

clean:
	rm -rf *.o set_calculator output.txt