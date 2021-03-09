/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 1: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará el tablero en blanco con la hormiga, esperando
que una tecla sea pulsada para inicializar)
$ make clean
*/

#ifndef JAIL
#define JAIL

#include <assert.h>
#include <iostream>
#include <string>

#define UP "\u2191"
#define UP_LEFT "\u2B09"
#define UP_RIGHT "\u2B08"
#define LEFT "\u2190"
#define RIGHT "\u2192"
#define DOWN "\u2193"
#define DOWN_LEFT "\u2B0B"
#define DOWN_RIGHT "\u2B0A"

using namespace std;

class Jail {
private:
  struct values {
    char state_;
    string direction_;  
  } myvalues;
    
public:
  Jail(void);
  ~Jail();

  // Getters
  const char get_state(void);
  const string get_direction(void);
  
  // Setters
  void set_state(const char state);
  void set_direction(const string direction);
  
  // Overloads
  friend std::ostream & operator << (std::ostream &out, Jail &jail);
};

#endif