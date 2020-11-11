#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Dfa {
private:
  vector<char> alphabet_;
  vector<string> states_;
  string initialstate_;
  vector<string> finalstates_;
  // matriz delta de transciciones 8x3 para este ejemplo 
  // string transitions_[][];
  vector<vector<string>> transitions_;
  
  int linecounter_;
  
  int size_;

public:
  Dfa();
  ~Dfa();

  // Getters
  string get_initialstate(void);
  int get_linecounter(void);
  // Setters
  void set_initialstate(string);
  void set_linecounter(int);
  void set_size(int);
  // Methods
  void ReadForBuild(void); // Revisar para ahorrar mas lineas de codigos en los builds
  void BuildAlphabet(void);
  void BuildStates(void);
  void BuildInitialState(void);
  void BuildFinalStates(void);
  void BuildTrasitions(void);
  void ResizeTransitions(int);
};


