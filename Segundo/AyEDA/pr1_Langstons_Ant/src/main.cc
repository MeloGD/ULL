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

#include "../include/world.h"
#include "../include/ant.h"
#include "../include/jail.h"
#include <stdlib.h>

int main(void) {
  World mundo(100,100);
  Ant hormiga (mundo,55,49,'>');
  int iterator = 0;

  mundo.Print_World();
  getchar();
  do {  
    system("clear");
    mundo.Print_World();
    hormiga.Run_Ant(mundo);
    iterator++;
    //getchar();
  } while (iterator < 10200);

  return 0;
}
