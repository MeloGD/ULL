/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Computabilidad y Algoritmia.

Práctica 7: Simulador de un DFA
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Motivo: Realizar un simulador de un DFA que será construido siguiendo la
sintaxis descrita en el input.dfa. En dicho dfa, solo se admiten cadenas
sin son números binarios divisibles por 3 (11, que es 3, sería admitido).
Las cadenas son evaluadas desde un input.txt y la solución estára alojada 
en output.txt
*/
#include "dfa.h"
#include "grammar.h"

/**
 * @brief Constructor y destructor por defecto .
*/
Dfa::Dfa(string dfafile) {
  BuildAlphabet(dfafile);
  BuildStates(dfafile);
  BuildInitialState(dfafile);
  BuildFinalStates(dfafile);
  BuildTrasitions(dfafile);
};

Dfa::~Dfa() {};

// Getters
/**
 * @brief Devuelve el estado inicial cargado en el input.dfa .
*/
string Dfa::get_initialstate(void) {
  return initialstate_;
}

/**
 * @brief Devuelve el último nº de línea que se ha leído en input.dfa .
*/
int Dfa::get_linecounter(void) {
  return linecounter_;
}

vector<char> Dfa::get_alphabet(void) {
  return alphabet_;
}

vector<string> Dfa::get_states(void) {
  return states_;
}

vector<string> Dfa::get_finalstates(void) {
  return finalstates_;
}

matrixofstrings Dfa::get_transitions(void) {
  return transitions_;
}

// Setters
/**
 * @brief Asigna el estado inicial.
 * @param state Estado leído.
*/
void Dfa::set_initialstate(string state) {
  initialstate_ = state;
}

/**
 * @brief Asigna el nº el último nº de línea que se ha leído.
 * @param number Nº de línea.
*/
void Dfa::set_linecounter(int number) {
  linecounter_ = number;
}

// Methods
/**
 * @brief Método que se usa en el main_dfa para cargar los ficheros de
 * entrada/salida. Cada línea del input.txt es pasada al RunDfa() para
 * su evaluación. Cada línea del input.txt es pada al RunDfa()
 * @param inputfile Fichero de entrada con las cadenas a evaluar
 * @param dfafile Nombre del fichero que contiene la información del dfa.
 * @param outputfile Fichero de salida con la solución
*/
void Dfa::ReadAndWriteFile(string inputfile, string outputfile) {
  fstream file;
  string chain;
  file.open(inputfile);
  while (getline(file, chain)) {
    RunDfa(chain, outputfile);
  }
  file.close();
}

/**
 * @brief Llama a la construcción de los atributos si no han sido construidos
 * previamente. LLama a RunTransitions() para evaluar las cadenas recibidas.
 * Dependiendo de la evaluación, se le pasa un tipo de flag al WriteFile().
 * @param chain Cadena a evaluar
 * @param dfafile Nombre del fichero que contiene la información del dfa.
 * @param outputfile Fichero de salida con la solución
*/
void Dfa::RunDfa(string chain, string outputfile) {
  int flag = 0;
  if (alphabet_[0] == '0' && chain[0] == '0' && chain.size() > 1) {
    WriteFile(outputfile, chain, flag);
  } else {
    if (RunTransitions(chain)) {
      flag = 1;
      WriteFile(outputfile, chain, flag);
    } else {
      flag = 2;
      WriteFile(outputfile, chain, flag);
    }
  }
}

/**
 * @brief Recorre la matriz de transiciones desde el estado inicial y
 * lo actualiza en función del símbolo contiene la cadena.
 * @param chain La cadena a estudiar.
 * @return true Si la cadena finaliza en un estado de aceptación.
 * @return false Si la cadena finaliza en un estado distinto a aceptación.
*/
bool Dfa::RunTransitions(string chain) {
  string currentstate = get_initialstate();
  for (auto i = 0; i < chain.size(); i++) {
    char symbol = chain[i];
    for (unsigned j = 0; j < transitions_.size(); j++) {
      if (transitions_[j][0] == currentstate 
          && transitions_[j][1][0] == symbol) {
          currentstate = transitions_[j][2];
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

/**
 * @brief Escribe el fichero de soluciones
 * @param outputfile Fichero de salida
 * @param chain Cadena a escribir
 * @param flag 0-> Si empieza por 0; 1->Si es aceptada; 2->No es aceptada.
*/
void Dfa::WriteFile(string outputfile, string chain, int flag) {
  fstream file;
  file.open(outputfile, fstream::out | fstream::app);
  if (flag == 0) {
    file << chain << " --> Comienza con un cero. Debe quitarlo para ser evaluado.\n";
  } else if (flag == 1) {
    file << chain << " --> Sí.\n";
  } else if (flag == 2) {
    file << chain << " --> No.\n";
  }
  file.close();
}

/**
 * @brief Construye el alfabeto desde *.dfa. Si el nº de elementos es x, solo
 * cargará x líneas y fija el número de líneas cargadas con
 * set_linecounter(line) para tenerlo en cuenta en BuildStates().
 * @param dfafile Nombre del fichero que contiene la información del dfa.
*/

void Dfa::BuildAlphabet(string dfafile) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  bool sizeobtained = false;
  file.open(dfafile);
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

/**
 * @brief Construye los estados desde *.dfa. Si el nº de elementos es x, solo
 * cargará x líneas y fija el número de líneas cargadas con
 * set_linecounter(line) para tenerlo en cuenta en BuildInitialState().
 * @param dfafile Nombre del fichero que contiene la información del dfa.
*/
void Dfa::BuildStates(string dfafile) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  file.open(dfafile);
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

/**
 * @brief Construye el estado inicial desde *.dfa. Si el nº de inicios es x,
 * solo cargará x líneas y fija el número de líneas cargadas con
 * set_linecounter(line) para tenerlo en cuenta en BuildFinalStates().
 * @param dfafile Nombre del fichero que contiene la información del dfa.
*/
void Dfa::BuildInitialState(string dfafile) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  file.open(dfafile);
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

/**
 * @brief Construye los estados finales desde *.dfa. Si el nº de estados es x,
 * solo cargará x líneas y fija el número de líneas cargadas con
 * set_linecounter(line) para tenerlo en cuenta en BuildTransitions().
 * @param dfafile Nombre del fichero que contiene la información del dfa.
*/
void Dfa::BuildFinalStates(string dfafile) {
  ifstream file;
  string information;
  int line = 0;
  int maxline = 1;
  file.open(dfafile);
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

/**
 * @brief Construye la matriz de delta transiciones desde *.dfa. 
 * Si el nº de estados es x, solo cargará x líneas. En la primera iteración
 * del while, se llama a ResizeTransitions() para redimensionar la matriz 
 * con las filasxcolumnas necesarias.
 * @param dfafile Nombre del fichero que contiene la información del dfa.
*/
void Dfa::BuildTrasitions(string dfafile) {
  ifstream file;
  string information;
  string subinformation;
  int line = 0;
  int maxline = 1;
  int row = 0;
  int column = 0;
  int position = 0;
  file.open(dfafile);
  bool sizeobtained = false;
  while (getline(file, information)) {
    if ((line >= get_linecounter()) && (sizeobtained == false)) {
      maxline = stoi(information);
      ResizeTransitions(maxline);
      sizeobtained = true;
    } else if ((line >= get_linecounter()) && (sizeobtained == true)) {
      while (position < information.size()) { 
        if (information[position] != ' ') {
          subinformation.push_back(information[position]);
        } else {
          transitions_[row][column] = subinformation;
          subinformation.clear();
          column++;
        }
        if (position == (information.size() - 1)) {
          transitions_[row][column] = subinformation;
          subinformation.clear();
        }
        position++; 
      }
      row++;
      column = 0;
      position = 0;
    }
    line++;
  }
  file.close();
  set_linecounter(line); 
}

/**
 * @brief Redimensiona la matriz para dejarla lista y poder depositar
 * las transiciones de los estados.
 * @param row Valor recibido por BuildTransitios()
 */
void Dfa::ResizeTransitions(int row) {
  transitions_.resize(row);
  for (int i = 0; i < row; i++) {
    transitions_[i].resize(3);
  }
}

Grammar* Dfa::ConvertToGrammar(void) {
  
  
  return grammar_;
}
