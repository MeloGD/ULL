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

#include "../include/ant.h"

// Constructor
Modified_Ant::Modified_Ant() {}

Modified_Ant::Modified_Ant(World &mundo, int x, int y, string direction) {
  Place_Ant(mundo,x,y,direction);
}

// Destructor
Modified_Ant::~Modified_Ant() {
  
};

// Functions
/*
void Modified_Ant::Place_Ant(World &mesh, int x, int y, string dir) {
  assert(x < mesh.get_row() && y < mesh.get_column());
  set_currentx(x);
  set_currenty(y);
  mesh.At_Position(x,y).set_direction(dir);
}
*/

void Modified_Ant::Run_Ant(Infinite_World &mesh) {
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

void Modified_Ant::Move_Up(Infinite_World &mesh) {
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

void Modified_Ant::Move_Left(Infinite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() - 1;
  if (aux < 0) {
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

void Modified_Ant::Move_Right(Infinite_World &mesh) {
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

void Modified_Ant::Move_Down(Infinite_World &mesh) {
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

void Modified_Ant::Move_Up_Left(Infinite_World &mesh) {
  Move_Up(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Left(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP_LEFT);
  set_direction(UP_LEFT);
}

void Modified_Ant::Move_Up_Right(Infinite_World &mesh) {
  Move_Up(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Right(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP_RIGHT);
  set_direction(UP_RIGHT);
}

void Modified_Ant::Move_Down_Left(Infinite_World &mesh) {
  Move_Down(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Left(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN_LEFT);
  set_direction(DOWN_LEFT);
}

void Modified_Ant::Move_Down_Right(Infinite_World &mesh) {
  Move_Down(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  Move_Right(mesh);
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN_RIGHT);
  set_direction(DOWN_RIGHT);
}

void Modified_Ant::Run_Antf(Finite_World &mesh) {
  if (mesh.At_Position( get_currentx() , get_currenty() ).get_state() == '0') {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('X');
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP) {
      Move_Leftf(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == LEFT) {
      Move_Downf(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == RIGHT) {
      Move_Upf(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN) {
      Move_Rightf(mesh);
    }
  } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_state() == 'X'){
    mesh.At_Position( get_currentx() , get_currenty() ).set_state('0');
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == UP) {
      Move_Rightf(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == LEFT) {
      Move_Upf(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == RIGHT) {
      Move_Downf(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == DOWN) {
      Move_Leftf(mesh);
    }    
  }
}

void Modified_Ant::Move_Upf(Finite_World &mesh) { 
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currentx() - 1;
  if (aux < 0) {
    aux = mesh.get_row() - 1;
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP);
    set_direction(UP);
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(UP);
    set_direction(UP);
  } 
}

void Modified_Ant::Move_Leftf(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() - 1;
  if (aux < 0) {
    aux = mesh.get_column() - 1;
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(LEFT);
    set_direction(LEFT);
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(LEFT);
    set_direction(LEFT);
  } 
}

void Modified_Ant::Move_Rightf(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currenty() + 1;
  if (aux >= mesh.get_column()) {
    aux -= mesh.get_column() ;
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(RIGHT);
    set_direction(RIGHT);
  } else {
    set_currenty(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(RIGHT);
    set_direction(RIGHT);
  } 
}

void Modified_Ant::Move_Downf(Finite_World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(" ");
  int aux = get_currentx() + 1;
  if (aux >= mesh.get_row()) {
    aux -= mesh.get_row();
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN);
    set_direction(DOWN);
  } else {
    set_currentx(aux);
    mesh.At_Position( get_currentx() , get_currenty() ).set_direction(DOWN);
    set_direction(DOWN);
  } 
}

// Overloads
/*
Ant& Ant::operator=(Ant& ant) {
  set_direction(ant.get_direction());
  set_currentx(ant.get_currentx());
  set_currenty(ant.get_currenty());
  
  return *this;
}
*/