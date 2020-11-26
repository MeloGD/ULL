all: dfa

dfa: main_dfa.o dfa.o
	g++ -std=c++14 -g -Wall -o dfa main_dfa.o dfa.o

clean:
	rm -rf *.o dfa output.txt
