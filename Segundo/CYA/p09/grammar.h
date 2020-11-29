#ifndef GRAMMAR 
#define GRAMMAR

#include "dfa.h"

// Gramática
class Grammar {
private:
  vector<char> terminalsymbols_;
  vector<string> nonterminalsymbols_;
  vector<string> productions_;
  string start_;
  
public:
  Grammar();
  Grammar(Dfa &dfatogrammar);
  ~Grammar();

  // Getters
  vector<char> get_terminalsymbols(void);
  vector<string> get_nonterminalsymbols(void);
  string get_start(void);
  vector<string> get_productions(void);
  
  // Setters 
  void set_terminalsymbols(vector<char> symbols);
  void set_nonterminalsymbols(vector<string> states);
  void set_start(string start);
  void set_productions(matrixofstrings transitions, vector<string> finalstates);

  // Methods
  void BuildFinalProductions(vector<string> finalstates);
  void WriteFile(string grammarfile);
};

#endif