/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 2: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará el tablero en blanco con la hormiga, esperando
que una tecla sea pulsada para inicializar)
$ make clean
*/

#include "../include/jail.h"

// Constructor
Jail::Jail(void) {
  // By default is '0', which means white. 'X' means black.
  set_state('0');
  set_direction(" ");
};

// Destrutor
Jail::~Jail() {} 

// Getters
const char Jail::get_state(void) {
  return myvalues.state_;
}

const string Jail::get_direction(void) {
  return myvalues.direction_;
}

// Setters
void Jail::set_state(const char state) {
  assert(state == '0' || state == 'X' );
  myvalues.state_ = state;
}

void Jail::set_direction(const string direction) {
  assert(direction == UP || direction == DOWN || direction == RIGHT || 
        direction == LEFT || direction == " " || direction == UP_LEFT || 
        direction == UP_RIGHT || direction == DOWN_LEFT|| direction == DOWN_RIGHT);
  myvalues.direction_ = direction;
}

// Overloads
std::ostream& operator << (std::ostream &out, Jail &jail) {
  return out << jail.myvalues.state_ << jail.myvalues.direction_;
}