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

#ifndef UNIVERSE
#define UNIVERSE

#include "../include/ant.h"
#include "../include/world.h"

class Universe {
private:
  int steps_;
  int rows_;
  int columns_;
  World world_;

public:
  Universe(const int steps, const int rows, const int columns);
  Universe(World& world);
  ~Universe();

  // Getters
  const int get_steps(void);
  const int get_rows(void);
  const int get_columns(void);

  // Setters
  void set_steps(const int steps);
  void set_rows(const int rows);
  void set_columns(const int columns);

  // Functions
  void Run_Universe(char typeworld);
};

#endif
