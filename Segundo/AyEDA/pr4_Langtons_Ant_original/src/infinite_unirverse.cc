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
Infinite_Universe::Infinite_Universe(const int steps, const int rows, const int columns) {
  set_steps(steps);
  set_rows(rows);
  set_columns(columns);
}

Infinite_Universe::Infinite_Universe(World& world, std::vector<Ant*>& antlist) {
  infworld_ = world;
  set_antlist(antlist);
}

// Destructor
Infinite_Universe::~Infinite_Universe() {}

// Functions

void Infinite_Universe::Run_Universe() {
  for (unsigned i = 0; i < antlist_.size(); i++) {
    //Ant *auxiliar_ant;
    // auxiliar_ant = &antlist_[i];
    
    short x = antlist_[i]->get_currentx();
    short y = antlist_[i]->get_currenty();
    std::string dir = antlist_[i]->get_direction();
    antlist_[i]->Place_Ant(infworld_, x, y, dir);
  }
  
  infworld_.Print_World();
  getchar();
  Infinite_World();
  

}

void Infinite_Universe::Infinite_World() {
  int steps = 0, oldx = 0, oldy = 0, newx = 0, newy = 0;  
  

  do {  
    system("clear");
    infworld_.Print_World();
    
    for (unsigned i = 0; i < antlist_.size(); i++) {
      oldx = infworld_.get_row();
      oldy = infworld_.get_column();
      antlist_[i]->Run_Ant(infworld_);
      newx = infworld_.get_row();
      newy = infworld_.get_column();       
      if (oldx != newx && oldy != newy && antlist_[i]->get_resizenegative()) {
        for (unsigned j = 0; j < antlist_.size(); j++) {
          if (j != i) {
            antlist_[j]->Place_Ant(infworld_,(antlist_[j]->get_currentx() + 1),
                                          (antlist_[j]->get_currenty() + 1), 
                                          antlist_[j]->get_direction());
          }
        }
      } else if (oldy != newy && antlist_[i]->get_resizenegative() ) {
        for (unsigned j = 0; j < antlist_.size(); j++) {
          if (j != i) {
            antlist_[j]->Place_Ant(infworld_,(antlist_[j]->get_currentx()),
                                          (antlist_[j]->get_currenty() + 1), 
                                          antlist_[j]->get_direction());
          }
        }
      }  else if (oldx != newx && antlist_[i]->get_resizenegative()) {
        for (unsigned j = 0; j < antlist_.size(); j++) {
          if (j != i) {
            antlist_[j]->Place_Ant(infworld_,(antlist_[j]->get_currentx() + 1),
                                          (antlist_[j]->get_currenty()), 
                                          antlist_[j]->get_direction());
          }
        }
      } else {
        for (unsigned j = 0; j < antlist_.size(); j++) {
            antlist_[j]->Place_Ant(infworld_,(antlist_[j]->get_currentx() ),
                                          (antlist_[j]->get_currenty()), 
                                          antlist_[j]->get_direction());
        }
      }
    }
    steps++;
    getchar();
  } while (steps < 1000); 
  
}
