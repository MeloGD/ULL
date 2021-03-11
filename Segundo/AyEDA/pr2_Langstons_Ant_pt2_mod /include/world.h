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

#ifndef WORLD
#define WORLD

#include "../include/jail.h"
//#include <vector>
#include "../include/vector_t.h"

class World {
private:
  int row_;
  int column_;
  // std::vector<std::vector<Jail>> mesh_;
  Vector_T<Vector_T<Jail>> mesh_;

public:
  World();
  World(int rows, int columns);
  ~World();

  // Getters
  const int get_row(void);
  const int get_column(void);
  const Vector_T<Vector_T<Jail>>& get_mesh(void);

  // Setters
  void set_row(const int row);
  void set_column(const int column);

  // Functions
  void Resize_World(int row, int column);
  void Resize_For_Move(int row, int column, World& mesh);
  Jail& At_Position(int row, int column);
  void Print_World(void);

};

#endif