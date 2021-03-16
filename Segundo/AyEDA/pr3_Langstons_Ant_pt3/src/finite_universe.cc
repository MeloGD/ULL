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


Finite_Universe::Finite_Universe(const int steps, const int rows, const int columns) {
  set_steps(steps);
  set_rows(rows);
  set_columns(columns);
}

Finite_Universe::Finite_Universe(Finite_World& world,  std::vector<Finite_Ant>& antlist) {
  fworld_ = world;
  set_antlist(antlist);
}

// Destructor
Finite_Universe::~Finite_Universe() {}

// Setters

void Finite_Universe::set_antlist(std::vector<Finite_Ant>& antlist) {
  fantlist_.resize(antlist.size());
  for (int i = 0; i < fantlist_.size(); i++){
    fantlist_[i] = antlist[i];
  }
}



// Functions

void Finite_Universe::Run_Universe() {
  
  
  for (int i = 0; i < fantlist_.size(); i++) {
    short x = fantlist_[i].get_currentx();
    short y = fantlist_[i].get_currenty();
    std::string dir = fantlist_[i].get_direction();
    fantlist_[i].Place_Ant(fworld_, x, y, dir);
  }
    
    int steps = 0, oldx = 0, oldy = 0, newx = 0, newy = 0;   
    fworld_.Print_World();
    getchar();
    
    do {  
      system("clear");
      fworld_.Print_World();
      for (int i = 0; i < fantlist_.size(); i++) {
        oldx = fworld_.get_row();
        oldy = fworld_.get_column();
        fantlist_[i].Run_Ant(fworld_);
        newx = fworld_.get_row();
        newy = fworld_.get_column(); 
      }
      steps++;
      getchar();
    } while (steps < 1000); 
    
}
