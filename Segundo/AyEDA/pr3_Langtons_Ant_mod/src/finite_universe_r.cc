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


Finite_Universe_R::Finite_Universe_R(const int steps, const int rows, const int columns) {
  set_steps(steps);
  set_rows(rows);
  set_columns(columns);
}

Finite_Universe_R::Finite_Universe_R(Finite_World_R& world,  std::vector<Ant>& antlist) {
  fworld_r = world;
  set_antlist(antlist);
}

// Destructor
Finite_Universe_R::~Finite_Universe_R() {}

// Functions
void Finite_Universe_R::Run_Universe() { 
  for (unsigned i = 0; i < antlist_.size(); i++) {
    short x = antlist_[i].get_currentx();
    short y = antlist_[i].get_currenty();
    std::string dir = antlist_[i].get_direction();
    antlist_[i].Place_Ant(fworld_r, x, y, dir);
  }
  int steps = 0;
  fworld_r.Print_World();
  getchar();
  do {  
    system("clear");
    fworld_.Print_World();
    for (unsigned i = 0; i < antlist_.size(); i++) {
      antlist_[i].Run_Antfr(fworld_r);
      for (unsigned j = 0; j < antlist_.size(); j++) {
        short x = antlist_[i].get_currentx();
        short y = antlist_[i].get_currenty();
        std::string dir = antlist_[i].get_direction();
        antlist_[i].Place_Ant(fworld_r, x, y, dir);
      }
    }
    steps++;
    getchar();
  } while (steps < 1000); 
}
