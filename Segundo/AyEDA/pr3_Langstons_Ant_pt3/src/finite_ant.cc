#include "../include/ant.h"

// Constructor
Finite_Ant::Finite_Ant() {}

Finite_Ant::Finite_Ant(Finite_World &mundo, int x, int y, string direction) {
  Place_Ant(mundo,x,y,direction);
}

// Destructor
Finite_Ant::~Finite_Ant() {}

void Finite_Ant::Run_Ant(Finite_World &mesh) {
  if (mesh.At_Position( get_currentx() , get_currenty() ).get_state() == '0') {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('X');
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP) {
      Move_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == LEFT) {
      Move_Down(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == RIGHT) {
      Move_Up(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN) {
      Move_Right(mesh);
    }
  } else {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('0');
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP) {
      Move_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == LEFT) {
      Move_Up(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == RIGHT) {
      Move_Down(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN) {
      Move_Left(mesh);
    }    
  }
  
}

void Finite_Ant::Move_Up(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currentx() - 1;
  if (aux < 0) {
    aux = mesh.get_row() - 1;
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP);
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP);
  } 
}

void Finite_Ant::Move_Left(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() - 1;
  if (aux < 0) {
    aux = mesh.get_column() - 1;
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(LEFT);
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(LEFT);
  } 
}

void Finite_Ant::Move_Right(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() + 1;
  if (aux >= mesh.get_column()) {
    aux -= mesh.get_column() ;
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(RIGHT);
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(RIGHT);
  } 
}

void Finite_Ant::Move_Down(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currentx() + 1;
  if (aux >= mesh.get_row()) {
    aux -= mesh.get_row();
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN);
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN);
  } 
}

// Overloads
Finite_Ant& Finite_Ant::operator=(Ant& ant) {
  set_currentstate(ant.get_currentstate());
  set_currentx(ant.get_currentx());
  set_currenty(ant.get_currenty());
  
  return *this;
}