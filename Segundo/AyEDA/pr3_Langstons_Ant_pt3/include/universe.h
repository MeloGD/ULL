/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 2: Hormiga de Langton
Año: 2020/2021
Autor: Jesús Carmelo González Domínguez
email: alu0101267760@ull.edu.es
Uso en terminal:
$ make run 
(una vez compilado, se mosntrará el tablero en blanco con la hormiga, esperando
que una tecla sea pulsada para inicializar)
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
  std::vector<Ant> antlist_;

protected:
  Finite_World fworld_;
  Infinite_World infworld_;
  std::vector<Infinite_Ant> infantlist_;
  std::vector<Finite_Ant> fantlist_;

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
  virtual void set_antlist(std::vector<Ant>& antlist);

  // Functions
  virtual void Run_Universe();
  //void Run_Universe(void);
  //void Run_Finite_Universe(void);

};

class Finite_Universe : public Universe {
private:
  /* data */
public:
  
  Finite_Universe(const int steps, const int rows, const int columns);
  Finite_Universe(Finite_World& world, std::vector<Finite_Ant>& antlist);
  ~Finite_Universe();

  // setters
  void set_antlist(std::vector<Finite_Ant>& antlist);

  // Functions 
  void Run_Universe();

  
};




class Infinite_Universe : public Universe {
private:
  /* data */
public:
  Infinite_Universe(const int steps, const int rows, const int columns);
  Infinite_Universe(Infinite_World& world, std::vector<Infinite_Ant>& antlist);
  ~Infinite_Universe();

  //setters
  void set_antlist(std::vector<Infinite_Ant>& antlist);

  // Functions
  void Run_Universe();

};




#endif
