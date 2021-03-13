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

#include "../include/universe.h"
#include "../include/world.h"
#include "../include/ant.h"
#include "../include/jail.h"

#include <stdlib.h>
#include <string>

int main(void) {
  /*
  char typeworld;
  int rows;
  int columns;
  int antcount;
  std::cout << "Bienvenido a la Hormiga de Langton" << std::endl;
  std::cout << "¿Desea un mundo finito o infinito? Especifique dimensiones" << std::endl;
  std::cout << " - Ejemplo: i 3 3 (infinito 3x3)" << std::endl;
  std::cin << typeworld << rows << columns;
  std::cout << "¿Cuantas hormigas desea ejecutar y en que posición?" << std::endl;
  */

  
  
  //Universe Universo(1000, 3, 3);
  World mundo(10,3);
  Universe universo(mundo);
  universo.Run_Universe('f');
  

  return 0;
}
