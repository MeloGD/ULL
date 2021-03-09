/*
Universidad de La Laguna.
Grado en Ingeniería Informática.
Asignatura de Algoritmos y Estructuras de Datos Avanzadas.
Práctica 1: Hormiga de Langton
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

#include "world.h"
#include "../include/jail.h"




class Ant {
private:
  short currentstate_;
  short currentx_;
  short currenty_;

public:
  Ant();
  Ant(World &mundo, int i, int j, string direction);
  ~Ant();

  // Getter
  const short get_currentstate(void);
  const short get_currentx(void);
  const short get_currenty(void);

  // Setter
  void set_currentstate(const short state);
  void set_currentx(const short currentx);
  void set_currenty(const short currenty);


  // Functions 
  void Place_Ant(World &mesh, int x, int y, string dir);
  void Run_Ant(World &mesh);
  void Move_Up(World &mesh);
  void Move_Up_Left(World &mesh);
  void Move_Up_Right(World &mesh);
  void Move_Left(World &mesh);
  void Move_Right(World &mesh);
  void Move_Down(World &mesh);
  void Move_Down_Left(World &mesh);
  void Move_Down_Right(World &mesh);
  
};

#endif
