#include "dfa.h"


Dfa::Dfa() {};
Dfa::~Dfa() {};

// Getters
string Dfa::get_initialstate(void) {
  return initialstate_;
}

int Dfa::get_linecounter(void) {
  return linecounter_;
}
// Setters
void Dfa::set_initialstate(string state) {
  initialstate_ = state;
}

void Dfa::set_linecounter(int number) {
  linecounter_ = number;
}



// Methods
void Dfa::BuildAlphabet(void) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  bool sizeobtained = false;
  file.open("input.dfa");
  while (getline(file, information) && maxline != 0) {
    if (information[0] != '/' && sizeobtained == false) {
      maxline = stoi(information);
      sizeobtained = true;
    } else if (information[0] != '/' && sizeobtained == true) {
      alphabet_.push_back(information[0]);
      maxline--;
    }
    line++;
  }
  file.close();
  set_linecounter(line);
}

void Dfa::BuildStates(void) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  file.open("input.dfa");
  bool sizeobtained = false;
  while (getline(file, information) && maxline != 0) {
    if ((line >= get_linecounter()) && (sizeobtained == false)) {
      maxline = stoi(information);
      sizeobtained = true;
    } else if ((line >= get_linecounter()) && (sizeobtained == true)) {
      states_.push_back(information);
      maxline--;
    }
    line++;
  }
  file.close();
  set_linecounter(line);
}

void Dfa::BuildInitialState(void) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  file.open("input.dfa");
  while (getline(file, information) && maxline != 0) {
    if ((line >= get_linecounter())) {
      set_initialstate(information);
      maxline--;
    }
    line++;
  }
  file.close();
  set_linecounter(line);
}

void Dfa::BuildFinalStates(void) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  file.open("input.dfa");
  bool sizeobtained = false;
  while (getline(file, information) && maxline != 0) {
    if ((line >= get_linecounter()) && (sizeobtained == false)) {
      maxline = stoi(information);
      sizeobtained = true;
    } else if ((line >= get_linecounter()) && (sizeobtained == true)) {
      finalstates_.push_back(information);
      maxline--;
    }
    line++;
  }
  file.close();
  set_linecounter(line); 
}

void Dfa::BuildTrasitions(void) {
  ifstream file;
  string information;
  string subinformation;
  int line = 0;
  int maxline = 1;
  int row = 0;
  int column = 0;
  int i = 0;
  file.open("input.dfa");
  bool sizeobtained = false;
  while (getline(file, information)) {
    if ((line >= get_linecounter()) && (sizeobtained == false)) {
      maxline = stoi(information);
      ResizeTransitions(maxline);
      sizeobtained = true;
    } else if ((line >= get_linecounter()) && (sizeobtained == true)) {
      while (i < information.size()) { // recorre la string del getline
        if (information[i] != ' ') {
          subinformation.push_back(information[i]);
        } else {
          transitions_[row][column] = subinformation;
          subinformation.clear();
          column++;
        }
        if (i == (information.size() - 1)) {
          transitions_[row][column] = subinformation;
          subinformation.clear();
        }
        i++; 
      }
      row++;
      column = 0;
      i = 0;
    }
    line++;
  }
  file.close();
  set_linecounter(line);
}

void Dfa::ResizeTransitions(int row) {
  transitions_.resize(row);
  for (int i = 0; i < row; i++) {
    transitions_[i].resize(3);
  }
}