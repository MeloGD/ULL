#include "ant.h"

// Constructor
Ant::Ant() { }

// Destructor
Ant::~Ant() {}

// Getters
const short Ant::get_currentstate(void) {
  return currentstate_;
}

const short Ant::get_oldstate(void) {
  return oldstate_;
}

const short Ant::get_currentx(void) {
  return currentx_;
}

const short Ant::get_currenty(void) {
  return currenty_;
}

const short Ant::get_oldx(void) {
  return oldx_;
}

const short Ant::get_oldy(void) {
  return oldy_;
}
// Setters
void Ant::set_currentstate(const short state) {
  currentstate_ = state;
}

void Ant::set_oldstate(const short oldstate) {
  oldstate_ = oldstate;
}

void Ant::set_currentx(const short currentx) {
  currentx_ = currentx;
}

void Ant::set_currenty(const short currenty) {
  currenty_ = currenty;
}

void Ant::set_oldx(const short oldx) {
  oldx_ = oldx;
}

void Ant::set_oldy(const short oldy) {
  oldy_ = oldy;
}

// Functions
void
Ant::Place_Ant(World &mesh, int x, int y, char dir) {
  set_currentx(x);
  set_currenty(y);
  mesh.At_Position(x,y).set_state(0);
  mesh.At_Position(x,y).set_direction(dir);
}

void Ant::Run_Ant(World &mesh) {
  if (mesh.At_Position( get_currentx() , get_currenty() ).get_state() == 0) {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state(1);
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == '^') {
      Move_Left(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == '<') {
      Move_Down(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == '>') {
      Move_Up(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == 'v') {
      Move_Right(mesh);
    }
  } else {
    mesh.At_Position( get_currentx() , get_currenty() ).set_state(0);
    if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == '^') {
      Move_Right(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == '<') {
      Move_Up(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == '>') {
      Move_Down(mesh);
    } else if (mesh.At_Position( get_currentx() , get_currenty() ).get_direction() == 'v') {
      Move_Left(mesh);
    }    
  }
  
}

void Ant::Move_Up(World &mesh) {
  mesh.At_Position( get_currentx() , get_currenty() ).set_direction(' ');
  set_oldx( get_currentx() );
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
  set_oldy( get_currenty() );
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
  set_oldy( get_currenty() );
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
  set_oldx( get_currentx() );
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
