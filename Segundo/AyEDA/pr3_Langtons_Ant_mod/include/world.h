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
  Vector_T<Vector_T<Jail>>& get_mesh(void);

  // Setters
  void set_row(const int row);
  void set_column(const int column);
  void set_mesh(Vector_T<Vector_T<Jail>>& mesh);

  // Functions
  void Resize_World(int row, int column);
  Jail& At_Position(int row, int column);
  void Print_World(void);

  // Overloads
  World& operator=(World& world);

};

class Finite_World : public World {
private:

public:
  Finite_World();
  Finite_World(int rows, int columns);
  ~Finite_World();

  // Overloads
  Finite_World& operator=(World& world);

};


class Finite_World_R : public Finite_World {
private:
  /* data */
public:
  Finite_World_R(/* args */);
  Finite_World_R(int rows, int columns);
  ~Finite_World_R();

  // Overloads
  Finite_World_R& operator=(Finite_World& world);
};

class Finite_World_T : public Finite_World {
private:
  /* data */
public:
  Finite_World_T(/* args */);
  Finite_World_T(int rows, int columns);
  ~Finite_World_T();

  // Functions
  // Overloads
  Finite_World_T& operator=(World& world);

};




class Infinite_World : public World {
private:

public:
  Infinite_World();
  Infinite_World(int rows, int columns);
  ~Infinite_World();

  // Functions
  void Resize_For_Move(int row, int column, Infinite_World& mesh);

  // Overloads
  Infinite_World& operator=(World& world);

};



#endif