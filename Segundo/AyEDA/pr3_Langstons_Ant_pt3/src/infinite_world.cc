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

#include "../include/world.h"

// Constructor
Infinite_World::Infinite_World() {}

Infinite_World::Infinite_World(int columns, int rows) {
  Resize_World(rows, columns);
}

// Destructor
Infinite_World::~Infinite_World() {}

// Functions
void Infinite_World::Resize_For_Move(int row, int column, Infinite_World& mesh) {
  Vector_T<Vector_T<Jail>> auxiliar;
  auxiliar.Resize(mesh.get_row());
  for (int i = 0; i < mesh.get_row(); i++) {
    auxiliar[i].Resize(mesh.get_column());   
  }
  for (int j = 0; j < mesh.get_row(); j++) {
    for (int k = 0; k < mesh.get_column(); k++) {
        auxiliar[j][k] = mesh.At_Position(j,k); // cambio de mesh_ a mesh.At
    }    
  }
  if (row < 0) {
    mesh.Resize_World(mesh.get_row() + 1, mesh.get_column());
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh.At_Position(j + 1,k) = auxiliar[j][k];
      }    
    }
  } else if (column < 0) {
    mesh.Resize_World(mesh.get_row(), mesh.get_column() + 1);
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh.At_Position(j, k + 1) = auxiliar[j][k];
      }
    }
  } else if (column > 0) {
    mesh.Resize_World(mesh.get_row(), mesh.get_column() + 1);
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh.At_Position(j, k) = auxiliar[j][k];
      }    
    }
  } else if (row > 0) {
    mesh.Resize_World(mesh.get_row() + 1, mesh.get_column());
    for (int j = 0; j < auxiliar.get_size(); j++) {
      for (int k = 0; k < auxiliar[j].get_size(); k++) {
        mesh.At_Position(j, k) = auxiliar[j][k];
      }    
    } 
  }
};


