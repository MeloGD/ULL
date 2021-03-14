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

#ifndef ANT
#define ANT

#include "../include/world.h"
#include "../include/jail.h"




class Ant {
private:
  std::string direction_;
  short currentx_;
  short currenty_;

public:
  Ant();
  Ant(World &mundo, int i, int j, string direction);
  ~Ant();

  // Getter
  const std::string get_direction(void);
  const short get_currentx(void);
  const short get_currenty(void);

  // Setter
  void set_direction(const std::string direction);
  void set_currentx(const short currentx);
  void set_currenty(const short currenty);

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

  // Overloads
  Ant& operator=(Ant& ant);
  
};

class Infinite_Ant : public Ant{
private:
  
public:
  Infinite_Ant(/* args */);
  Infinite_Ant(Infinite_World &mundo, int i, int j, string direction);
  ~Infinite_Ant();

  // Overloads
  Infinite_Ant& operator=(Ant& ant);
};

class Finite_Ant : public Ant{
private:
  
public:
  Finite_Ant(/* args */);
  Finite_Ant(Finite_World &mundo, int i, int j, string direction);
  ~Finite_Ant();

   // Functions 
  //void Place_Ant(World &mesh, int x, int y, string dir);
  void Run_Ant(Finite_World &mesh);
  void Move_Up(Finite_World &mesh);
  void Move_Up_Left(Finite_World &mesh);
  void Move_Up_Right(Finite_World &mesh);
  void Move_Left(Finite_World &mesh);
  void Move_Right(Finite_World &mesh);
  void Move_Down(Finite_World &mesh);
  void Move_Down_Left(Finite_World &mesh);
  void Move_Down_Right(Finite_World &mesh);
  

  // Overloads
  Finite_Ant& operator=(Ant& ant);
};


#endif
