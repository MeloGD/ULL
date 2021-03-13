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
  int antcount;
  std::cout << "Bienvenido a la Hormiga de Langton" << std::endl;
  std::cout << "¿Desea un mundo finito o infinito?" << std::endl;
  std::cout << " - Escriba i para infinito." << std::endl;
  std::cout << " - Escriba f para finito." << std::endl;
  std::cout << "¿Cuantas hormigas desea ejecutar y en que posición?" << std::endl;
  */

  
  
  Universe Universo(1000, 3, 3);
  Universo.Run_Universe('i');
  

  return 0;
}
