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

#include "grammar.h"

// int argc, char const *argv[]
int main() {
  string help = "--help";
  vector<string> test;
  Grammar gramamrtest("input.dfa");


  /*
  if (argc == 1) {
    cout << "Ejecute ./dfa --help para obetener más información." << endl;
  }
  if (argc == 2 && argv[1] == help) {
    cout << "--help" << endl;
    cout << "Ejemplo:" << endl;
    cout << "./dfa input.dfa input.txt output.txt" << endl;
    cout << "input.dfa: Contiene la sitaxis que describe el dfa." << endl;
    cout << "input.txt: Las cadenas a estudiar." << endl;
    cout << "output.txt: El resultado de su evaluación." << endl;
  } else if (argc == 2 && argv[1] != help) {
    cout << "[ERROR]" << endl;
    cout << "Ejecute ./dfa --help para obetener más información." << endl;
  } 
  if (argc == 4) {
    Dfa dfasimulator1(argv[1]);
    dfasimulator1.ReadAndWriteFile(argv[2], argv[3]);
  } else if (argc != 4 && argc != 1 && argc != 2) {
    cout << "[ERROR]" << endl;
    cout << "Ejecute ./dfa --help para obetener más información." << endl;
  }
  */ 
  return 0;
}
