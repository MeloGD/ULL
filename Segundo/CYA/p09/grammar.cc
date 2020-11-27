#include "grammar.h"

Grammar::Grammar(string dfafile) {
  Dfa dfaforgrammar(dfafile);
  BuildTerminalSymbols(dfaforgrammar);
  BuildNonTerminalSymbols(dfaforgrammar);
  start_ = dfaforgrammar.get_initialstate();
  BuildProductions(dfaforgrammar);
}

Grammar::~Grammar() {

}

// Getters
vector<char> Grammar::get_terminalsymbols(void) {
  return terminalsymbols_;
}

vector<string> Grammar::get_nonterminalsymbols(void) {
  return nonterminalsymbols_;
}

string Grammar::get_start(void) {
  return start_;
}
// Setters

// Methods
void Grammar::BuildTerminalSymbols(Dfa dfaforgrammar) {
  vector<char> temporaryvector(dfaforgrammar.get_alphabet());
  for (unsigned i = 0; i < temporaryvector.size(); i++) {
    terminalsymbols_.push_back(temporaryvector[i]);   
  }
}

void Grammar::BuildNonTerminalSymbols(Dfa dfaforgrammar) {
  vector<string> temporaryvector(dfaforgrammar.get_states());
  for (unsigned i = 0; i < temporaryvector.size(); i++) {
    nonterminalsymbols_.push_back(temporaryvector[i]);   
  }
}

void Grammar::BuildProductions(Dfa dfaforgrammar) {
  matrixofstrings temporarymatrix(dfaforgrammar.get_transitions());
  vector<string> finalstates(dfaforgrammar.get_finalstates());
  string data;
  string accepted;
  string current = get_start(); // esto va a valer A
  bool newproduction = true;
  bool foundfinal = false;
  int count = 0; 
  for (auto i = 0; i < temporarymatrix.size(); i++) {
    if (current == temporarymatrix[i][0]) {
      if (newproduction) {
        data = current;
        data += " -> ";
        newproduction = false;
      }
      data.push_back(temporarymatrix[i][1][0]);
      data = data + temporarymatrix[i][2];
      // cout << data << " data vale"<< endl;
      if (terminalsymbols_.back() != temporarymatrix[i][1][0]) {
        data.push_back('|');
      } else {
        for (auto position = 0; position < finalstates.size(); position++) {
          string finalstate = finalstates[position];
          if (current == finalstate) {
            // cout << "hola" << endl;
            foundfinal = true;
          }
        }
        if (foundfinal) {
          accepted = current;
          accepted += " -> ~"; 
          //cout << data << " data vale"<< endl;
          productions_.push_back(data);
          productions_.push_back(accepted);
          accepted.clear();
        } else {
          //cout << data << " data else vale"<< endl;
          productions_.push_back(data);
          data.clear();
        }
      } 
    } else {
      foundfinal = false;
      newproduction = true;
      current = temporarymatrix[i][0];
      i--;
    }
  }
  for (auto j = 0; j < finalstates.size(); j++) {
    auto lenght = finalstates[j].size();
    string finalstate = finalstates[j];
    auto once = 0;
    bool found = false;
    for (auto i = 0; i < productions_.size(); i++) {
      string state = productions_[i].substr(0, lenght);
      if (finalstate == state) {
        found = true;
      }
    }
    if (found == false) {
      data.clear();
      data = finalstate;
      data += " -> ~";
      productions_.push_back(data);
    }
  }
    
    
  
  for (int i = 0; i < productions_.size(); i++)
  {
    cout << productions_[i] << endl;
  }
}


