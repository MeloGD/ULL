all: grammar

grammar: main_dfa.o dfa.o grammar.o
	g++ -std=c++14 -g -Wall -o grammar main_dfa.o dfa.o grammar.o

clean:
	rm -rf *.o grammar output.txt
