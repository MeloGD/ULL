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

#include "../include/world.h"

// Constructor
Finite_World::Finite_World() {}

Finite_World::Finite_World(int rows, int columns) {
  World::Resize_World(rows, columns);
}

// Destructor
Finite_World::~Finite_World() {}


// Overloads
Finite_World& Finite_World::operator=(World& world) {
  set_row(world.get_row());
  set_column(world.get_column());
  set_mesh(world.get_mesh());
  
  return *this;
}


