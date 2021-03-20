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
#include "../include/world.h"

// Constructor
Finite_World_R::Finite_World_R() {}

Finite_World_R::Finite_World_R(int rows, int columns) {
  World::Resize_World(rows, columns);
}

// Destructor
Finite_World_R::~Finite_World_R() {}


// Overloads

// Overloads
Finite_World_R& Finite_World_R::operator=(Finite_World& world) {
  set_row(world.get_row());
  set_column(world.get_column());
  set_mesh(world.get_mesh());
  
  return *this;
}