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


int main(int argc, char const *argv[]) {
  string help = "--help";
  if (argc == 1) {
    cout << "Ejecute ./grammar --help para obetener más información." << endl;
  }
  if (argc == 2 && argv[1] == help) {
    cout << "--help" << endl;
    cout << "Ejemplo:" << endl;
    cout << "./grammar input.dfa output.gra" << endl;
    cout << "input.dfa: Contiene la sitaxis que describe el dfa." << endl;
    cout << "output.gra: El resultado de la gramática converida." << endl;
  } else if (argc == 2 && argv[1] != help) {
    cout << "[ERROR]" << endl;
    cout << "Ejecute ./grammar --help para obetener más información." << endl;
  } 
  if (argc == 3) {
    Dfa dfasimulation(argv[1]);
    Grammar grammarsimulation;
    grammarsimulation = dfasimulation.ConvertToGrammar();
    grammarsimulation.WriteFile(argv[2]);
  } else if (argc != 3 && argc != 1 && argc != 2) {
    cout << "[ERROR]" << endl;
    cout << "Ejecute ./grammar --help para obetener más información." << endl;
  }
  
  return 0;
}
