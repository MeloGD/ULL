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
World::World() {}

World::World(int rows, int columns) {
  Resize_World(rows, columns);
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
void World::Resize_World(int row, int column) {
  set_row(row);
  set_column(column);
  
  mesh_.Resize(row);
  for (int i = 0; i < get_row(); i++) {
    mesh_[i].Resize(column);   
  }
  /*
  for (int j = 0; j < get_row(); j++) {
    for (int k = 0; k < get_row(); k++) {
        Jail aux;
        mesh_[j][k] = aux;
    }    
  }*/
}


void World::Resize_For_Move(int row, int column, World& mesh) {
  Vector_T<Vector_T<Jail>> auxiliar;
  auxiliar.Resize(mesh.get_row());
  for (int i = 0; i < mesh.get_row(); i++) {
    auxiliar[i].Resize(mesh.get_column());   
  }
  for (int j = 0; j < mesh.get_row(); j++) {
    for (int k = 0; k < mesh.get_column(); k++) {
        auxiliar[j][k] = mesh_[j][k];
    }    
  }
  if (row < 0) {
    mesh.Resize_World(mesh.get_row() + 1, mesh.get_column());
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh_[j + 1][k] = auxiliar[j][k];
      }    
    }
  } else if (column < 0) {
    mesh.Resize_World(mesh.get_row(), mesh.get_column() + 1);
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh_[j][k + 1] = auxiliar[j][k];
      }
    }
  } else if (column > 0) {
    mesh.Resize_World(mesh.get_row(), mesh.get_column() + 1);
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh_[j][k] = auxiliar[j][k];
      }    
    }
  } else if (row > 0) {
    mesh.Resize_World(mesh.get_row() + 1, mesh.get_column());
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh_[j][k] = auxiliar[j][k];
      }    
    } 
  }
};

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

