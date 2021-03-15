/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 2: Hormiga de Langton Modificada
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

Ant::Ant(World &mundo, int x, int y, string direction) {
  Place_Ant(mundo,x,y,direction);
}

// Destructor
Ant::~Ant() {}

// Getters
const std::string Ant::get_direction(void) {
  return direction_;
}

const short Ant::get_currentx(void) {
  return currentx_;
}

const short Ant::get_currenty(void) {
  return currenty_;
}

const bool Ant::get_resizenegative(void) {
  return resizenegative_;
}


// Setters
void Ant::set_direction(std::string direction) {
  direction_ = direction;
}

void Ant::set_currentx(const short currentx) {
  currentx_ = currentx;
}

void Ant::set_currenty(const short currenty) {
  currenty_ = currenty;
}

void Ant::set_resizenegative(const bool resize) {
  resizenegative_ = resize;
}

// Functions
void Ant::Place_Ant(World &mesh, int x, int y, string dir) {
  assert(x < mesh.get_row() && y < mesh.get_column());
  set_currentx(x);
  set_currenty(y);
  //mesh.At_Position(x,y).set_state('0');
  mesh.At_Position(x,y).set_direction(dir);
}

void Ant::Run_Ant(Infinite_World &mesh) {
  if (mesh.At_Position( get_currentx() , get_currenty() ).get_state() == '0') {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('X');
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP) {
      Move_Up_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == LEFT) {
      Move_Down_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == RIGHT) {
      Move_Up_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN) {
      Move_Down_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP_LEFT) {
      Move_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP_RIGHT) {
      Move_Up(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN_LEFT) {
      Move_Down(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN_RIGHT) {
      Move_Right(mesh);
    }
  } else {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('0');
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP) {
      Move_Up_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == LEFT) {
      Move_Up_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == RIGHT) {
      Move_Down_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN) {
      Move_Down_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP_LEFT) {
      Move_Up(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP_RIGHT) {
      Move_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN_LEFT) {
      Move_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN_RIGHT) {
      Move_Down(mesh);
    } 
  }
}

void Ant::Move_Up(Infinite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currentx() - 1;
  if (aux < 0) {
    set_resizenegative(true);
    set_currentx(0);
    mesh.Resize_For_Move(aux,get_currenty(), mesh);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP);
    set_direction(UP);
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP);
    set_direction(UP);
  } 
}

void Ant::Move_Left(Infinite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() - 1;
  if (aux < 0) {
    //aux = mesh.get_column() - 1;
    set_resizenegative(true);
    set_currenty(0);
    mesh.Resize_For_Move(get_currentx(),aux, mesh);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(LEFT);
    set_direction(LEFT);
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(LEFT);
    set_direction(LEFT);
  } 
}

void Ant::Move_Right(Infinite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() + 1;
  if (aux >= mesh.get_column()) {
    set_resizenegative(false);
    set_currenty(aux);
    mesh.Resize_For_Move(0,aux, mesh);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(RIGHT);
    set_direction(RIGHT);
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(RIGHT);
    set_direction(RIGHT);
  } 
}

void Ant::Move_Down(Infinite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currentx() + 1;
  if (aux >= mesh.get_row()) {
    set_resizenegative(false);
    set_currentx(aux);
    mesh.Resize_For_Move(aux,0, mesh);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN);
    set_direction(DOWN);
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN);
    set_direction(DOWN);
  } 
}

void Ant::Move_Up_Left(Infinite_World &mesh) {
  Move_Up(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Left(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP_LEFT);
  set_direction(UP_LEFT);
}

void Ant::Move_Up_Right(Infinite_World &mesh) {
  Move_Up(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Right(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP_RIGHT);
  set_direction(UP_RIGHT);
}

void Ant::Move_Down_Left(Infinite_World &mesh) {
  Move_Down(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Left(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN_LEFT);
  set_direction(DOWN_LEFT);
}

void Ant::Move_Down_Right(Infinite_World &mesh) {
  Move_Down(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Right(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN_RIGHT);
  set_direction(DOWN_RIGHT);
}

std::string& Ant::Fix_Direction(std::string direction) {
  if (direction == "up") {
    direction = UP;
  } else if (direction == "right") {
    direction = RIGHT;
  } else if (direction == "left") {
    direction = LEFT;
  } else if (direction == "down") {
    direction = DOWN;
  } else if (direction == "upright") {
    direction = UP_RIGHT;
  } else if (direction == "upright") {
    direction = UP_RIGHT;
  } else if (direction == "upleft") {
    direction = UP_LEFT;
  } else if (direction == "downright") {
    direction = DOWN_RIGHT;
  } else if (direction == "downleft") {
    direction = DOWN_LEFT;
  }
}


// Overloads
Ant& Ant::operator=(Ant& ant) {
  set_direction(ant.get_direction());
  set_currentx(ant.get_currentx());
  set_currenty(ant.get_currenty());
  
  return *this;
}