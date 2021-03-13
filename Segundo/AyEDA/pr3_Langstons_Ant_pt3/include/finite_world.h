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
#ifndef FINITE_WORLD
#define FINITE_WORLD

#include "../include/jail.h"
#include "../include/vector_t.h"

class Finite_World {
private:
  int row_;
  int column_;
  Vector_T<Vector_T<Jail>> mesh_;

public:
  Finite_World();
  Finite_World(int rows, int columns);
  ~Finite_World();

  // Getters
  const int get_row(void);
  const int get_column(void);
  const Vector_T<Vector_T<Jail>>& get_mesh(void);

  // Setters
  void set_row(const int row);
  void set_column(const int column);

  // Functions
  void Resize(int row, int column);
  Jail& At_Position(int row, int column);
  void Print_Finite_World(void);

};

#endif