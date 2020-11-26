#include "dfa.h"


Dfa::Dfa() {
  BuildAlphabet();
};
Dfa::~Dfa() {};

// Getters
string Dfa::get_initialstate(void) {
  return initialstate_;
}

int Dfa::get_linecounter(void) {
  return linecounter_;
}

bool Dfa::get_isbuilt(void) {
  return isbuilt_;
}

// Setters
void Dfa::set_initialstate(string state) {
  initialstate_ = state;
}

void Dfa::set_linecounter(int number) {
  linecounter_ = number;
}

void Dfa::set_isbuilt(bool built) {
  isbuilt_ = built;
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

void Dfa::ReadAndWriteFile(string inputfile, string outputfile) {
  fstream file;
  string information;
  file.open(inputfile);
  while (getline(file, information)) {
    RunDfa(information, outputfile);
  }
  file.close();
}

void Dfa::WriteFile(string name, string chain, int flag) {
  fstream file;
  file.open(name, fstream::out | fstream::app);
  if (flag == 0) {
    file << chain << " --> Comienza con un cero. Debe quitarlo para ser evaluado.\n";
  } else if (flag == 1) {
    file << chain << " --> Sí.\n";
  } else if (flag == 2) {
    file << chain << " --> No.\n";
  }
  file.close();
}

void Dfa::RunDfa(string chain, string outputfile) {
  int flag = 0;
  if (!get_isbuilt()) {
    BuildAlphabet();
    BuildStates();
    BuildInitialState();
    BuildFinalStates();
    BuildTrasitions();
    set_isbuilt(true);
  }
  if (alphabet_[0] == '0' && chain[0] == '0' && chain.size() > 1) {
    WriteFile(outputfile, chain, flag);
  } else {
    if (RunTransitions(chain)) {
      flag = 1;
      WriteFile(outputfile, chain, flag);
      // Aquí llamo a mi WriteTrace() y listo
    } else {
      flag = 2;
      WriteFile(outputfile, chain, flag);
    }
  }
}

bool Dfa::RunTransitions(string chain) {
  string currentstate = get_initialstate();
  for (auto i = 0; i < chain.size(); i++) {
    char symbol = chain[i];
    for (unsigned j = 0; j < transitions_.size(); j++) {
      if (transitions_[j][0] == currentstate && transitions_[j][1][0] == symbol) {
          currentstate = transitions_[j][2];
          cout << transitions_[j][0] << " "  << symbol << " " << currentstate << endl;
          j = transitions_.size();
      }
    }
  }
  for (auto i = 0 ; i < finalstates_.size(); i++) {
    if (finalstates_[i] == currentstate) {
      return true;
    } else if (i == (finalstates_.size() - 1)) {
      return false;
    }    
  }
}
