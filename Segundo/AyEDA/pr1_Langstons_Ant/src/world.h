#ifndef WORLD
#define WORLD

#include "jail.h"
#include <vector>


class World {
private:
  int row_;
  int column_;
  std::vector<std::vector<Jail>> mesh_;
  
  /*
  int position(int i, int j) const {
    return (i - 1) * column_ + j - 1;
  }*/
public:
  World();
  ~World();

  // Getters
  const int get_row(void);
  const int get_column(void);
  const std::vector<std::vector<Jail>>& get_mesh(void);

  // Setters
  void set_row(const int row);
  void set_column(const int column);

  // Functions
  void Resize(int row, int column);
  Jail& At_Position(int row, int column);
  void Print_World(void);

  // Overloads
  // friend std::ostream & operator << (std::ostream &out, World &world);
};

#endif