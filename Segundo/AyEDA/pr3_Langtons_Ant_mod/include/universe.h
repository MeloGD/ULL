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

#ifndef UNIVERSE
#define UNIVERSE

#include "../include/ant.h"
#include "../include/world.h"
#include <vector>

class Universe {
private:
  int steps_;
  int rows_;
  int columns_;
  World world_;

protected:
  Finite_World fworld_;
  Finite_World_R fworld_r;
  Finite_World_T fworld_t;
  Infinite_World infworld_;
  std::vector<Ant> antlist_;

public:
  Universe();
  Universe(const int steps, const int rows, const int columns);
  Universe(World& world, std::vector<Ant>& antlist);
  ~Universe();

  // Getters
  const int get_steps(void);
  const int get_rows(void);
  const int get_columns(void);

  // Setters
  void set_steps(const int steps);
  void set_rows(const int rows);
  void set_columns(const int columns);
  void set_antlist(std::vector<Ant>& antlist);

  // Functions
  virtual void Run_Universe() = 0;

};

class Finite_Universe : public Universe {
private:
  /* data */
public:
  Finite_Universe();
  Finite_Universe(const int steps, const int rows, const int columns);
  Finite_Universe(Finite_World& world, std::vector<Ant>& antlist);
  ~Finite_Universe();

  // Functions 
  virtual void Run_Universe() = 0;
  
};

class Finite_Universe_R : public Finite_Universe {
private:
  /* data */
public:
  
  Finite_Universe_R(const int steps, const int rows, const int columns);
  Finite_Universe_R(Finite_World_R& world, std::vector<Ant>& antlist);
  ~Finite_Universe_R();

  // Functions 
  void Run_Universe();
  
};

class Finite_Universe_T : public Finite_Universe {
private:
  /* data */
public:
  
  Finite_Universe_T(const int steps, const int rows, const int columns);
  Finite_Universe_T(Finite_World_T& world, std::vector<Ant>& antlist);
  ~Finite_Universe_T();

  // Functions 
  void Run_Universe();
  
};

class Infinite_Universe : public Universe {
private:
  /* data */
public:
  Infinite_Universe(const int steps, const int rows, const int columns);
  Infinite_Universe(World& world, std::vector<Ant>& antlist);
  ~Infinite_Universe();

  // Functions
  void Run_Universe();
  void Infinite_World();

};

#endif
