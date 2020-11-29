#include "grammar.h"



Grammar::Grammar(){

}

/*
Grammar::Grammar(Dfa &dfatogrammar) {
  BuildTerminalSymbols(dfatogrammar);
  BuildNonTerminalSymbols(dfatogrammar);
  start_ = dfatogrammar.get_initialstate();
  BuildProductions(dfatogrammar);
}*/

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

vector<string> Grammar::get_productions(void) {
  return productions_;
}

// Setters
void Grammar::set_terminalsymbols(vector<char> symbols) {
  for (unsigned i = 0; i < symbols.size(); i++) {
    terminalsymbols_.push_back(symbols[i]);   
  }
}

void Grammar::set_nonterminalsymbols(vector<string> states) {
  for (unsigned i = 0; i < states.size(); i++) {
    nonterminalsymbols_.push_back(states[i]);   
  }
}

void Grammar::set_start(string initialstate) {
  start_ = initialstate;
}

void Grammar::set_productions(matrixofstrings transitions, vector<string> finalstates) {
  string data;
  string accepted;
  string current = get_start(); 
  bool newproduction = true;
  bool foundfinal = false;
  for (auto index = 0; index < transitions.size(); index++) {
    if (current == transitions[index][0]) {
      if (newproduction) {
        data = current + " -> ";
        newproduction = false;
      }
      data.push_back(transitions[index][1][0]);
      data += transitions[index][2];
      if (terminalsymbols_.back() != transitions[index][1][0]) {
        data.push_back('|');
      } else {
        for (auto position = 0; position < finalstates.size(); position++) {
          string finalstate = finalstates[position];
          if (current == finalstate) {
            foundfinal = true;
          }
        }
        if (foundfinal) {
          accepted = current + " -> ~";
          productions_.push_back(data);
          productions_.push_back(accepted);
          accepted.clear();
        } else {
          productions_.push_back(data);
          data.clear();
        }
      } 
    } else {
      foundfinal = false;
      newproduction = true;
      current = transitions[index][0];
      index--;
    }
  }
  BuildFinalProductions(finalstates); 
}

// Methods
void Grammar::BuildFinalProductions(vector<string> finalstates) {
  string data;
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
}

void Grammar::WriteFile(string grammarfile) {
  ofstream file;
  file.open(grammarfile, ofstream::app);
  file << terminalsymbols_.size() << endl;
  for (auto position = 0; position < terminalsymbols_.size(); position++) {
    file << terminalsymbols_[position] << endl;
  }
  file << nonterminalsymbols_.size() << endl;
  for (auto position = 0; position < nonterminalsymbols_.size(); position++) {
    file << nonterminalsymbols_[position] << endl;
  }
  file << get_start() << endl;
  file << productions_.size() << endl;
  for (auto position = 0; position < productions_.size(); position++) {
    file << productions_[position] << endl;
  }
  file.close();  
}

