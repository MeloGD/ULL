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

class Jail {
private:
  struct values {
    char state_;
    char direction_;  
  } myvalues;
    
public:
  Jail(void);
  ~Jail();

  // Getters
  const char get_state(void);
  const char get_direction(void);
  
  // Setters
  void set_state(const char state);
  void set_direction(const char direction);
  
  // Overloads
  friend std::ostream & operator << (std::ostream &out, Jail &jail);
};

#endif