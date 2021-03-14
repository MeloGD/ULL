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

Universe::Universe(World& world, Ant& ant) {
  world_ = world;
  ant_ = ant;
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
    Run_Infinite_Universe();
  } else {
    Run_Infinite_Universe();
  }
}

void Universe::Run_Infinite_Universe(void) {
    Infinite_World mundo;
    mundo = world_;
    world_.~World();
    Infinite_Ant hormiga;
    hormiga = ant_;
    ant_.~Ant();
    int steps = 0;
    Infinite_Ant hormiga2(mundo,0,0,UP);
    mundo.Print_World();
    getchar();
    int oldx = 0;
    int oldy = 0;
    int newx = 0;
    int newy = 0;
    do {  
      system("clear");
      mundo.Print_World();
      // guardar valores de columna actuales
      oldx = mundo.get_row();
      oldy = mundo.get_column();
      hormiga.Run_Ant(mundo);
      newx = mundo.get_row();
      newy = mundo.get_column();
      
      if (oldx != newx) {
        newx -= oldx;
        /*
        std::cout << oldx << std::endl;
        std::cout << newx << std::endl;
        
        int valx, valy = 0;
        hormiga2.Place_Ant(mundo, newx, hormiga2.get_currenty(), " ");
        valx = hormiga2.get_currentx();
        valy = hormiga2.get_currenty();
        */
        hormiga2.set_currentx(newx);
        
      }
      
      // guardar nuevos y comparar, si cambian, corregir la siguiente hormiga
      // con place_ant 
      hormiga2.Run_Ant(mundo);
      
      steps++;
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