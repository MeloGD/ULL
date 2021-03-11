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

  Universe Universo(1000, 3, 3);
  Universo.Run_Universe();

  return 0;
}
