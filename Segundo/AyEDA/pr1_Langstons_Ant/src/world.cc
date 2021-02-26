#include "world.h"

// Constructor
World::World() {

}

// Destructor
World::~World() { 

}

// Getters
const int
World::get_row(void) {
  return row_;
};

const int
World::get_column(void) {
  return column_;
};

// Setters
void
World::set_row(const int row) {
  row_ = row;
};

void
World::set_column(const int column) {
  column_ = column;
};

// Functions
void
World::Resize(int row, int column) {
  set_row(row);
  set_column(column);
  /*
  mesh_ = new Jail*[row];
  for (int i = 0; i < get_row(); i++) {
    mesh_[i] = new Jail[column];   
  }
  mesh_[1][1].set_state(1);
  mesh_[0][1].set_state(1);
  for (int i = 0; i < get_row(); i++) {
    for (int j = 0; j < get_column(); j++) {
      std::cout << mesh_[i][j].get_state() ;
    } 
  std::cout << std::endl;  
  }*/
  mesh2.resize(row);
  for (int i = 0; i < get_row(); i++) {
    mesh2[i].resize(column);   
  }
  mesh2[1][2].set_state(1);
  for (int i = 0; i < get_row(); i++) {
    for (int j = 0; j < get_column(); j++) {
      std::cout << mesh2[i][j].get_state() ;
    } 
  std::cout << std::endl;
  }
   
}

/*
Jail&
World::At(int row, int column) {
  for (int i = 0; i < row; i++) {
     for (int j = 0; j < column; j++) {
       return mesh_[i][j];
    } 
  }
}*/

// Overloads
