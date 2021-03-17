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
Infinite_Universe::Infinite_Universe(const int steps, const int rows, const int columns) {
  set_steps(steps);
  set_rows(rows);
  set_columns(columns);
}

Infinite_Universe::Infinite_Universe(Infinite_World& world,  std::vector<Infinite_Ant>& antlist) {
  infworld_ = world;
  set_antlist(antlist);
}

// Destructor
Infinite_Universe::~Infinite_Universe() {}

// Setters

void Infinite_Universe::set_antlist(std::vector<Infinite_Ant>& antlist) {
  infantlist_.resize(antlist.size());
  for (int i = 0; i < infantlist_.size(); i++){
    infantlist_[i] = antlist[i];
  }
}


// Functions

void Infinite_Universe::Run_Universe() {
    // PASAR TODO ESTE CODIGO AL MUNDO
    int steps = 0, oldx = 0, oldy = 0, newx = 0, newy = 0;   
    for (int i = 0; i < infantlist_.size(); i++) {
      short x = infantlist_[i].get_currentx();
      short y = infantlist_[i].get_currenty();
      std::string dir = infantlist_[i].get_direction();
      infantlist_[i].Place_Ant(infworld_, x, y, dir);
    }
    
    infworld_.Print_World();
    getchar();
    do {  
      system("clear");
      infworld_.Print_World();
      for (int i = 0; i < infantlist_.size(); i++) {
        oldx = infworld_.get_row();
        oldy = infworld_.get_column();
        infantlist_[i].Run_Ant(infworld_);
        newx = infworld_.get_row();
        newy = infworld_.get_column();       
        if (oldx != newx && oldy != newy && infantlist_[i].get_resizenegative()) {
          for (int j = 0; j < infantlist_.size(); j++) {
            if (j != i) {
              //std::cout << "j valen: " << j << endl;
              //newx -= oldx;
              //newy -= oldy;
              infantlist_[j].Place_Ant(infworld_,(infantlist_[j].get_currentx() + 1),
                                            (infantlist_[j].get_currenty() + 1), 
                                            infantlist_[j].get_direction());
            }
          }
        } else if (oldy != newy && infantlist_[i].get_resizenegative() ) {
          for (int j = 0; j < infantlist_.size(); j++) {
            if (j != i) {
              //newy -= oldy;
              infantlist_[j].Place_Ant(infworld_,(infantlist_[j].get_currentx()),
                                            (infantlist_[j].get_currenty() + 1), 
                                            infantlist_[j].get_direction());
            }
          }
        }  else if (oldx != newx && infantlist_[i].get_resizenegative()) {
          for (int j = 0; j < infantlist_.size(); j++) {
            if (j != i) {
              //newy -= oldy;
              infantlist_[j].Place_Ant(infworld_,(infantlist_[j].get_currentx() + 1),
                                            (infantlist_[j].get_currenty()), 
                                            infantlist_[j].get_direction());
            }
          }
        } else {
          for (int j = 0; j < infantlist_.size(); j++) {
              //newy -= oldy;
              infantlist_[j].Place_Ant(infworld_,(infantlist_[j].get_currentx() ),
                                            (infantlist_[j].get_currenty()), 
                                            infantlist_[j].get_direction());
                
          }
        }
      }
      steps++;
      getchar();
    } while (steps < 1000); 
    
}

