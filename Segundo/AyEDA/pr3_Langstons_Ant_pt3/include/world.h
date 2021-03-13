#ifndef WORLD
#define WORLD

#include "../include/jail.h"
#include "../include/vector_t.h"

class World {
private:
  int row_;
  int column_;
  Vector_T<Vector_T<Jail>> mesh_;

public:
  World();
  World(int rows, int columns);
  ~World();

  // Getters
  const int get_row(void);
  const int get_column(void);
  const Vector_T<Vector_T<Jail>>& get_mesh(void);

  // Setters
  void set_row(const int row);
  void set_column(const int column);

  // Functions
  // finito
  void Resize_World(int row, int column);
  Jail& At_Position(int row, int column);
  void Print_World(void);

  // infinito
  //void Resize_Infinite_World(int row, int column);
  //void Print_Infinite_World(void);

  //void Resize_For_Move(int row, int column, Infinite_World& mesh);

};


class Finite_World : public World {
private:

public:
  Finite_World();
  Finite_World(int rows, int columns);
  ~Finite_World();

};

class Infinite_World : public World {
private:

public:
  Infinite_World();
  Infinite_World(int rows, int columns);
  ~Infinite_World();

  // Functions
  void Resize_For_Move(int row, int column, Infinite_World& mesh);

};

#endif