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

#include "../include/finite_world.h"

// Constructor
World::World() {}

World::World(int rows, int columns) {
  Resize(rows, columns);
}

// Destructor
World::~World() {}

// Getters
const int World::get_row(void) {
  return row_;
};

const int World::get_column(void) {
  return column_;
};

const Vector_T<Vector_T<Jail>>& World::get_mesh(void) {
  return mesh_;
}

// Setters
void World::set_row(const int row) {
  row_ = row;
};

void World::set_column(const int column) {
  column_ = column;
};

// Functions
void World::Resize(int row, int column) {
  set_row(row);
  set_column(column);

  mesh_.Resize(row);
  for (int i = 0; i < get_row(); i++) {
    mesh_[i].Resize(column);   
  }
  for (int j = 0; j < get_row(); j++) {
    for (int k = 0; k < get_row(); k++) {
        Jail aux;
        mesh_[j][k] = aux;
    }    
  }
}

Jail& World::At_Position(int row, int column) {
  return mesh_[row][column];
}

void World::Print_World(void) {
  for (int i = 0; i < get_row(); i++) {
    for (int j = 0; j < get_column(); j++) {
      std::cout << mesh_[i][j];
    }
    std::cout << std::endl;
  }
}

