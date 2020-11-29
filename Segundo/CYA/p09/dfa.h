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
#ifndef DFA
#define DFA



#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

typedef vector<vector<string>> matrixofstrings;
/**
 * @brief Clase que simula el funcionamiento de un Dfa generando los cinco
 * elementos característicos del mismo: Un alfabeto; Estados; Estado
 * inicial; Estados finales; Delta, que este caso es una matriz (vector de
 * vectores de string) de transiciones.
 */
class Grammar;
class Dfa {
private:
  vector<char> alphabet_;
  vector<string> states_;
  string initialstate_;
  vector<string> finalstates_;
  matrixofstrings transitions_;
  /**
   * @brief Contador usado para delimitar hasta que línea se lee del fichero
   * input.dfa, para poder construir correctamente cada atributo.
   */
  int linecounter_;
  Grammar* grammar_;
   

public:
  // Constructor y destructor por defecto.
  Dfa(string dfafile);
  ~Dfa();

  // Getters
  string get_initialstate(void);
  int get_linecounter(void);
  vector<char> get_alphabet(void);
  vector<string> get_states(void);
  vector<string> get_finalstates(void);
  matrixofstrings get_transitions(void);
  // Setters
  void set_initialstate(string state);
  void set_linecounter(int number);
  // Methods
  void ReadAndWriteFile(string inputfile, string outputfile);
  void RunDfa(string chain, string outputfile);
  bool RunTransitions(string chain);
  void WriteFile(string outputfile, string chain, int flag);
  void BuildAlphabet(string dfafile);
  void BuildStates(string dfafile);
  void BuildInitialState(string dfafile);
  void BuildFinalStates(string dfafile);
  void BuildTrasitions(string dfafile); 
  void ResizeTransitions(int row);
  // Grammar* ConvertToGrammar(void); 
  Grammar ConvertToGrammar(void);
};

#endif