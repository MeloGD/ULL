#include "dfa.h"


class Grammar {
private:
  vector<char> terminalsymbols_;
  vector<string> nonterminalsymbols_;
  vector<string> productions_;
  string start_;
  
public:
  Grammar(string dfafile);
  ~Grammar();

  // Getters
  vector<char> get_terminalsymbols(void);
  vector<string> get_nonterminalsymbols(void);
  string get_start(void);
    // Setters

  // Methods
  void BuildTerminalSymbols(Dfa dfaforgrammar);
  void BuildNonTerminalSymbols(Dfa dfaforgrammar);
  void BuildStart(Dfa dfaforgrammar);
  void BuildProductions(Dfa dfaforgrammar);
  Grammar ConvertToGrammar(void);
};

