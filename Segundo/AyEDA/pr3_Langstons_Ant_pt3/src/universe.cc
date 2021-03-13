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

#include "../include/universe.h"
#include <stdlib.h>

// Constructor
Universe::Universe(const int steps, const int rows, const int columns) {
  set_steps(steps);
  set_rows(rows);
  set_columns(columns);
}

Universe::Universe(World& world) {
  world_ = world;
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


// Functions
void Universe::Run_Universe(char typeworld) {
  if (typeworld == 'i') {  
    Infinite_World mundo;
    mundo = world_;
    Ant hormiga( mundo, 0 , 0 , UP );
    int steps = 0;
    mundo.Print_World();
    getchar();
    do {  
      system("clear");
      mundo.Print_World();
      hormiga.Run_Ant(mundo);
      steps++;
      getchar();
    } while (steps < 1000);
  } else {
    Finite_World mundo;
    mundo = world_;
    Finite_Ant hormiga( mundo, 0 , 0 , UP );
    int steps = 0;
    mundo.Print_World();
    getchar();
    do {  
      system("clear");
      mundo.Print_World();
      hormiga.Run_Ant(mundo);
      steps++;
      getchar();
    } while (steps < 1000);
  }
  
  

  
}