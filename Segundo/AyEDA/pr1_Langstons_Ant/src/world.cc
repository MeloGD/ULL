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

const std::vector<std::vector<Jail>>&
World::get_mesh(void) {
  return mesh_;
}

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

  mesh_.resize(row);
  for (int i = 0; i < get_row(); i++) {
    mesh_[i].resize(column);   
  }
  for (int j = 0; j < get_row(); j++) {
    for (int k = 0; k < get_row(); k++) {
        Jail aux;
        mesh_[j][k] = aux;
    }    
  }
}

// creo que los for sobran MUCHISIMO, revisar mas adelante
Jail& World::At_Position(int row, int column) {
  return mesh_[row][column];
}

void
World::Print_World(void) {
  for (int i = 0; i < get_row(); i++) {
    for (int j = 0; j < get_column(); j++) {
      std::cout << mesh_[i][j] << "   ";
    }
    std::cout << std::endl;
  }
  
}
// Overloads
