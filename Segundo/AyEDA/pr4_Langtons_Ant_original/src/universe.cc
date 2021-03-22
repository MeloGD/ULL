/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 3: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará un menu de configuracion del tablero, nº de hormigas y su posición)
$ make clean
*/

#include "../include/universe.h"
#include <stdlib.h>

// Constructor
Universe::Universe(){

}

Universe::Universe(const int steps, const int rows, const int columns) {
  set_steps(steps);
  set_rows(rows);
  set_columns(columns);
}


Universe::Universe(World& world,  std::vector<Ant*>& antlist) {
  world_ = world;
  set_antlist(antlist);
}

// Destructor
Universe::~Universe() {}

// Getters
const int Universe::get_steps(void) {
  return steps_; 
}

const int Universe::get_rows(void) {
  return rows_; 
}

const int Universe::get_columns(void) {
  return columns_; 
}

// Setters
void Universe::set_steps(const int steps) {
  steps_ = steps;
}

void Universe::set_rows(const int rows) {
  rows_ = rows;
}

void Universe::set_columns(const int columns) {
  columns_ = columns;
}


void Universe::set_antlist(std::vector<Ant*> antlist) {
  antlist_.resize(antlist.size());
  for (unsigned i = 0; i < antlist_.size(); i++){
    antlist_[i] = antlist[i];
  }
}

void Universe::Run_Universe() {
  
}

