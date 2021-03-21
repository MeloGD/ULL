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

#ifndef ANT
#define ANT

#include "../include/world.h"
#include "../include/jail.h"

class Ant {
private:
  std::string direction_;
  short currentx_;
  short currenty_;
  bool resizenegative_;

public:
  Ant();
  Ant(World &mundo, int i, int j, string direction);
  ~Ant();

  // Getter
  const std::string get_direction(void);
  const short get_currentx(void);
  const short get_currenty(void);
  const bool get_resizenegative(void);

  // Setter
  void set_direction(const std::string direction);
  void set_currentx(const short currentx);
  void set_currenty(const short currenty);
  void set_resizenegative(const bool resize);

  // Functions 
  void Place_Ant(World &mesh, int x, int y, string dir);
  void Run_Ant(Infinite_World &mesh);
  void Move_Up(Infinite_World &mesh);
  void Move_Up_Left(Infinite_World &mesh);
  void Move_Up_Right(Infinite_World &mesh);
  void Move_Left(Infinite_World &mesh);
  void Move_Right(Infinite_World &mesh);
  void Move_Down(Infinite_World &mesh);
  void Move_Down_Left(Infinite_World &mesh);
  void Move_Down_Right(Infinite_World &mesh);
  std::string& Fix_Direction(std::string direction);

  //Finito
  void Run_Antf(Finite_World &mesh);
  void Move_Upf(Finite_World &mesh);
  //void Move_Up_Leftf(Finite_World &mesh);
  //void Move_Up_Rightf(Finite_World &mesh);
  void Move_Leftf(Finite_World &mesh);
  void Move_Rightf(Finite_World &mesh);
  void Move_Downf(Finite_World &mesh);
  //void Move_Down_Leftf(Finite_World &mesh);
  //void Move_Down_Rightf(Finite_World &mesh);

  // Overloads
  Ant& operator=(Ant& ant);
  
};

class Regular_Ant : public Ant {
private:

public:
  Regular_Ant();
  Regular_Ant(World &mundo, int i, int j, string direction);
  ~Regular_Ant();

};

class Modified_Ant : public Ant {
private:


public:
  Modified_Ant();
  Modified_Ant(World &mundo, int i, int j, string direction);
  ~Modified_Ant();

};

#endif
