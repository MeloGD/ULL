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

#include "../include/ant.h"

// Constructor
Ant::Ant() {}

Ant::Ant(World &mundo, int x, int y, char direction) {
  Place_Ant(mundo,x,y,direction);
}

// Destructor
Ant::~Ant() {}

// Getters
const short Ant::get_currentstate(void) {
  return currentstate_;
}

const short Ant::get_currentx(void) {
  return currentx_;
}

const short Ant::get_currenty(void) {
  return currenty_;
}


// Setters
void Ant::set_currentstate(const short state) {
  currentstate_ = state;
}

void Ant::set_currentx(const short currentx) {
  currentx_ = currentx;
}

void Ant::set_currenty(const short currenty) {
  currenty_ = currenty;
}

// Functions
void Ant::Place_Ant(World &mesh, int x, int y, char dir) {
  assert(x < mesh.get_row() && y < mesh.get_column());
  set_currentx(x);
  set_currenty(y);
  mesh.At_Position(x,y).set_state(' ');
  mesh.At_Position(x,y).set_direction(dir);
}

void Ant::Run_Ant(World &mesh) {
  // blanco - negro L
  if ((mesh.At_Position( get_currentx() , get_currenty()).get_state() == ' ' ) && 
      (mesh.At_Position( get_currentx() - 1 , get_currenty() + 1).get_state() == 'X' )) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('X');
    Move_Up(mesh);
    Move_Left(mesh);
  // negro - blanco L
  } else if ((mesh.At_Position( get_currentx() , get_currenty()).get_state() == 'X' ) && 
      (mesh.At_Position( get_currentx() - 1 , get_currenty() - 1).get_state() == ' ' )) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state(' ');  
    Move_Up(mesh);
    Move_Right(mesh);
  // Blanco - rojo Diagonal derecha
  } else if ((mesh.At_Position( get_currentx() , get_currenty()).get_state() == ' ' ) && 
      (mesh.At_Position( get_currentx() - 1 , get_currenty() + 1).get_state() == 'Y' )) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('Y');
    Move_Up(mesh);
    Move_Right(mesh);  
  // Rojo - blanco Diagonal izquierda  
  } else if ((mesh.At_Position( get_currentx() , get_currenty()).get_state() == 'Y' ) && 
      (mesh.At_Position( get_currentx() - 1 , get_currenty() - 1).get_state() == ' ' )) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state(' ');
    Move_Up(mesh);
    Move_Left(mesh);
  // Negro - rojo horizontal derecha  
  }  else if ((mesh.At_Position( get_currentx() , get_currenty()).get_state() == 'X' ) && 
      (mesh.At_Position( get_currentx() , get_currenty() + 1).get_state() == 'Y' )) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('Y');  
    Move_Right(mesh);
  // rojo - negro horizontal izquierda
  }  else if ((mesh.At_Position( get_currentx() , get_currenty()).get_state() == 'Y' ) && 
      (mesh.At_Position( get_currentx(), get_currenty() - 1).get_state() == 'X' )) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('X');  
    Move_Left(mesh);
  }
  
}

void Ant::Move_Up(World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(' ');
  int aux = get_currentx() - 1;
  if (aux < 0) {
    aux = mesh.get_row() - 1;
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('^');
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('^');
  } 
}

void Ant::Move_Left(World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(' ');
  int aux = get_currenty() - 1;
  if (aux < 0) {
    aux = mesh.get_column() - 1;
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('<');
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('<');
  } 
}

void Ant::Move_Right(World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(' ');
  int aux = get_currenty() + 1;
  if (aux >= mesh.get_column()) {
    aux -= mesh.get_column() ;
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('>');
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('>');
  } 
}

void Ant::Move_Down(World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(' ');
  int aux = get_currentx() + 1;
  if (aux >= mesh.get_column()) {
    aux -= mesh.get_column();
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('v');
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction('v');
  } 
}
