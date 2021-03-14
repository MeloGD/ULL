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

Universe::Universe(World& world,  std::vector<Ant> & antlist) {
  world_ = world;
  set_antlist(antlist);
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

void Universe::set_antlist(std::vector<Ant>& antlist) {
  antlist_.resize(antlist.size());
  for (int i = 0; i < antlist_.size(); i++){
    antlist_[i] = antlist[i];
  }
}


// Functions
void Universe::Run_Universe(char typeworld) {
  if (typeworld == 'i') {  
    Run_Infinite_Universe();
  } else {
    Run_Infinite_Universe();
  }
}

void Universe::Run_Infinite_Universe(void) {
    Infinite_World mundo;
    std::vector<Infinite_Ant> infinite_antlist;
    mundo = world_;
    infinite_antlist.resize(antlist_.size());
    for (int i = 0; i < antlist_.size(); i++) {
      infinite_antlist[i] = antlist_[i];
      short x = infinite_antlist[i].get_currentx();
      short y = infinite_antlist[i].get_currenty();
      std::string dir = infinite_antlist[i].get_direction();
      infinite_antlist[i].Place_Ant(mundo, x, y, dir);
    }
    int steps = 0, oldx = 0, oldy = 0, newx = 0, newy = 0;   
    mundo.Print_World();
    getchar();
    
    do {  
      system("clear");
      mundo.Print_World();
      for (int i = 0; i < infinite_antlist.size(); i++) {
        oldx = mundo.get_row();
        oldy = mundo.get_column();
        infinite_antlist[i].Run_Ant(mundo);
        newx = mundo.get_row();
        newy = mundo.get_column();
        std::cout << oldx << std::endl;
        std::cout << oldy << std::endl;
        std::cout << newx << std::endl;
        std::cout << newy << std::endl;
        getchar();
        
        if (oldx != newx && oldy != newy) {
          for (int j = 0; j < infinite_antlist.size(); j++) {
            if (j != i) {
              std::cout << "j i valen: " << j << i << endl;
              newx -= oldx;
              newy -= oldy;
              infinite_antlist[j].Place_Ant(mundo, newx, newy, " ");
            }
          }
        } /*
          else if (oldy != newy) {
          for (int j = 0; j < infinite_antlist.size(); j++) {
            if (j != i) {
              newy -= oldy;
              infinite_antlist[j].Place_Ant(mundo, infinite_antlist[j].get_currentx(), newy, " ");
            }
          }
        }*/
        
      }
      /*
      // guardar valores de columna actuales

      hormiga.Run_Ant(mundo);
      newx = mundo.get_row();
      newy = mundo.get_column();
      
      if (oldx != newx) {
        newx -= oldx;
        
        std::cout << oldx << std::endl;
        std::cout << newx << std::endl;
        
        int valx, valy = 0;
        hormiga2.Place_Ant(mundo, newx, hormiga2.get_currenty(), " ");
        valx = hormiga2.get_currentx();
        valy = hormiga2.get_currenty();
        /
        hormiga2.set_currentx(newx);
        
      }
      
      // guardar nuevos y comparar, si cambian, corregir la siguiente hormiga
      // con place_ant 
      hormiga2.Run_Ant(mundo);
      */
      steps++;
      //std::cout << steps << std::endl;
      getchar();
    } while (steps < 1000); 
    
}

void Universe::Run_Finite_Universe(void) {
      Finite_World mundo;
    mundo = world_;
    world_.~World();
    Finite_Ant hormiga;
    hormiga = ant_;
    ant_.~Ant();
    int steps = 0;
    Finite_Ant hormiga2(mundo,0,3,UP);
    mundo.Print_World();
    getchar();
    do {  
      system("clear");
      mundo.Print_World();
      hormiga.Run_Ant(mundo);
      hormiga2.Run_Ant(mundo);
      steps++;
      getchar();
    } while (steps < 1000);
}

